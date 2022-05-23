#ifndef CLIENT_H
#define CLIENT_H
#include <QtCore/QObject>
#include <QTextStream>
#include <QCoreApplication>
#include <QtDBus>
#include <QDebug>
#include <thread>

#include "reply.h"

class Client : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.qdbus.signalclient")
public:
    Client();
public slots:
    // void client_get(const QString &msg);
    void client_get(const Reply &reply);
signals:
    void send_to_server(const QString &msg);
};

#endif // CLIENT_H