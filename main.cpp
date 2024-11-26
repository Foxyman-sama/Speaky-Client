#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "network.h"
#include "chatmodel.h"

int main(int argc, char* argv[]) {
  QGuiApplication app(argc, argv);

  qmlRegisterType<ChatModel>("ChatModel", 1, 0, "ChatModel");

  QQmlApplicationEngine engine;
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreationFailed, &app, []() { QCoreApplication::exit(-1); },
      Qt::QueuedConnection);

  ChatModel model;
  engine.rootContext()->setContextProperty("chat_model", &model);

  Network network { model, nullptr };
  engine.rootContext()->setContextProperty("network", &network);

  engine.loadFromModule("Speaky-Client", "Main");

  return app.exec();
}
