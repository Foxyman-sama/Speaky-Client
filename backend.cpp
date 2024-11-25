#include "backend.h"
#include <QDebug>

Backend::Backend(QObject *parent)
    : QObject{parent}
{}

void Backend::print()
{
    qDebug() << "Hello, World!\n";
    emit printEmitted();
}
