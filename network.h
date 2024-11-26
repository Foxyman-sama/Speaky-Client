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
    try {
      connect();

      const RegistrationPackage registration_package { room_id.toStdString(), name.toStdString() };
      write_into_socket(socket, registration_package);

      const auto status_package { read_from_socket<StatusPackage>(socket) };
      if (status_package.status == "OK") {
        const auto message_package { read_from_socket<MessagePackage>(socket) };
        while (message_package.username.empty() == false) {
          model.append(message_package);
        }

        emit succesfulRegistrationEmitted();
      } else if (status_package.status == "NAME TAKEN") {
        emit nameTakenEmitted();
      }

    } catch (...) {
      emit failureRegistrationEmitted();
    }
  }

 signals:
  void succesfulRegistrationEmitted();
  void nameTakenEmitted();
  void failureRegistrationEmitted();

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
