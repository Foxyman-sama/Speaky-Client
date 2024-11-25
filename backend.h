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
    boost::asio::io_context context;
    boost::asio::ip::tcp::socket socket { context };
    boost::asio::ip::tcp::resolver::query resolver_query { "127.0.0.1", "9090",
                                                           boost::asio ::ip::tcp::resolver::query::numeric_service };
    boost::asio::ip::tcp::resolver resolver { context };
    auto it { resolver.resolve(resolver_query) };

    boost::asio::connect(socket, it);
    qDebug() << room_id << ' ' << name;
    emit printEmitted();
  }

 signals:
  void printEmitted();
};

#endif  // BACKEND_H
