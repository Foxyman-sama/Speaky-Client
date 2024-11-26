#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QQmlEngine>
#include <boost/asio.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <istream>
#include <ostream>

#include "Packages/packages.h"
#include "chatmodel.h"

class Network : public QObject {
  Q_OBJECT

 public:
  explicit Network(ChatModel& model, QObject* parent = nullptr) : model { model }, QObject { parent } {}

  Q_INVOKABLE void register_on_server(QString room_id, QString name) {
    connect();

    RegisterPackage register_package { room_id.toStdString(), name.toStdString() };
    const auto register_json { register_package.make_json() };

    std::ostringstream oss;
    boost::property_tree::write_json(oss, register_json);
    const auto json_str { oss.str() };
    const auto json_size { json_str.size() };

    InternetPackage internet_package;
    std::memcpy(internet_package.get_data(), &json_size, internet_package.header_lentgh);
    internet_package.reallocate();
    std::memcpy(internet_package.get_body(), json_str.c_str(), internet_package.get_body_length());

    boost::asio::write(socket,
                       boost::asio::buffer(internet_package.get_data(),
                                           internet_package.header_lentgh + internet_package.get_body_length()));

    emit register_on_serverEmitted();
  }

 signals:
  void register_on_serverEmitted();

 private:
  void connect() {
    boost::asio::ip::tcp::resolver::query resolver_query { "127.0.0.1", "9090",
                                                           boost::asio ::ip::tcp::resolver::query::numeric_service };
    boost::asio::ip::tcp::resolver resolver { context };
    auto it { resolver.resolve(resolver_query) };
    boost::asio::connect(socket, it);
  }

  boost::asio::io_context context;
  boost::asio::ip::tcp::socket socket { context };

  ChatModel& model;
};

#endif  // NETWORK_H
