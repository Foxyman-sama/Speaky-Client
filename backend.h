#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QQmlEngine>
#include <boost/asio.hpp>

class Backend : public QObject {
  Q_OBJECT
  QML_ELEMENT
 public:
  explicit Backend(QObject* parent = nullptr) : QObject { parent } {}

  Q_INVOKABLE void send(QString room_id, QString name) {
    if (is_connected == false) {
      connect();
    }

    const auto sent_data { room_id.toStdString() + ';' + name.toStdString() + '@' };
    boost::asio::write(socket, boost::asio::buffer(sent_data));
    qDebug() << "sent data: " << sent_data;

    emit sendEmitted();
  }

 signals:
  void sendEmitted();

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
  bool is_connected { false };
};

#endif  // BACKEND_H
