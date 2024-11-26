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

    // RegisterPackage register { "1", "Dima" };

    InternetPackage package;
    RegisterPackage p { "1", "Dima" };
    const auto json { p.make_json() };

    std::ostringstream oss;
    boost::property_tree::write_json(oss, json);

    const auto json_str { oss.str() };
    const auto json_size { json_str.size() };
    std::memcpy(package.get_data(), &json_size, package.header_lentgh);

    package.reallocate();
    std::memcpy(package.get_body(), json_str.c_str(), package.get_body_length());

    boost::asio::write(socket,
                       boost::asio::buffer(package.get_data(), package.header_lentgh + package.get_body_length()));

    emit register_on_serverEmitted();
  }

 signals:
  void register_on_serverEmitted();

 private:
  void send(QString sent_data) {
    boost::asio::write(socket, boost::asio::buffer(sent_data.toStdString()));
    qDebug() << "sent data: " << sent_data;
  }

  QString receive() {
    boost::asio::streambuf buf;
    boost::asio::read_until(socket, buf, '@');

    std::istream is { &buf };
    std::string received;
    std::getline(is, received, '@');
    qDebug() << "received data: " << received;
    return QString::fromStdString(received);
  }

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
