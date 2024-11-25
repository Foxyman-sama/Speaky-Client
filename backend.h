#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QQmlEngine>

class Backend : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit Backend(QObject *parent = nullptr);

    Q_INVOKABLE void print();

signals:
    void printEmitted();
};

#endif // BACKEND_H
