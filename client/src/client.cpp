#include "client.h"

Client::Client()
{
    QDBusConnection::sessionBus().unregisterService("com.qdbus.signalclient");
    QDBusConnection::sessionBus().registerService("com.qdbus.signalclient");
    QDBusConnection::sessionBus().registerObject("/com/qdbus/signalclient", this,
                                                 QDBusConnection ::ExportAllSlots | QDBusConnection ::ExportAllSignals);

    // "send_to_client" 是服务端定义的信号  此处监听服务端回复的信号
    // QDBusConnection::sessionBus().connect(QString(), QString("/com/qdbus/signalclient"), "com.qdbus.signalclient",
    //                                       "send_to_client", this, SLOT(client_get(const QString &)));

    QDBusConnection::sessionBus().connect(QString(), QString("/com/qdbus/signalclient"), "com.qdbus.signalclient",
                                          "send_to_client", this, SLOT(client_get(const Reply &)));
}

// void Client::client_get(const QString &msg)
// {
//     qInfo() << "client get msg from server:" << msg;
// }

void Client::client_get(const Reply &reply)
{
    qInfo() << "client get msg from server:" << reply.code << reply.message;
}