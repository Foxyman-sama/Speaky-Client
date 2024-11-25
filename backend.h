#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QQmlEngine>
#include <boost/asio.hpp>
#include <istream>

#include "chatmodel.h"

class Backend : public QObject {
  Q_OBJECT

 public:
  explicit Backend(QObject* parent = nullptr, ChatModel* model = nullptr) : QObject { parent }, model { model } {}

  Q_INVOKABLE void register_on_server(QString room_id, QString name) {
    connect();

    const auto sent_data { room_id.toStdString() + ';' + name.toStdString() + '@' };
    boost::asio::write(socket, boost::asio::buffer(sent_data));
    qDebug() << "sent data: " << sent_data;

    const auto status { receive() };
    if (status == "OK") {
      model->addUserMessage({ "Test", "Test" });
    }

    emit register_on_serverEmitted();
  }

 signals:
  void register_on_serverEmitted();

 private:
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

  ChatModel* model;
};

#endif  // BACKEND_H
