#ifndef SERVER_H
#define SERVER_H

#include <QtCore/QObject>
#include <QTextStream>
#include <QCoreApplication>
#include <QtDBus>
#include <QDebug>
#include <thread>

#include "reply.h"

class Server : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.qdbus.signalservice")
public:
    Server();
public slots:
    void server_get(const QString &msg);
signals:
    // void send_to_client(const QString &msg);
    void send_to_client(const Reply &reply);

private:
    void reply_client();
};

#endif