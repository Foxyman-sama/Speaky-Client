#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "backend.h"
#include "chatmodel.h"

int main(int argc, char* argv[]) {
  QGuiApplication app(argc, argv);

  qmlRegisterType<ChatModel>("ChatModel", 1, 0, "ChatModel");

  QQmlApplicationEngine engine;
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreationFailed, &app, []() { QCoreApplication::exit(-1); },
      Qt::QueuedConnection);

  Backend backend;
  engine.rootContext()->setContextProperty("backend", &backend);

  ChatModel model;
  engine.rootContext()->setContextProperty("chat_model", &model);

  engine.loadFromModule("Speaky-Client", "Main");

  return app.exec();
}
