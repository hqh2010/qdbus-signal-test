#include "server.h"

Server::Server()
{
    QDBusConnection::sessionBus().unregisterService("com.qdbus.signalservice");
    QDBusConnection::sessionBus().registerService("com.qdbus.signalservice");
    QDBusConnection::sessionBus().registerObject("/com/qdbus/signalservice", this,
                                                 QDBusConnection ::ExportAllSlots | QDBusConnection ::ExportAllSignals);
    // send_to_server 为客户端定义的dbus信号 监听发送的客户端的信号
    QDBusConnection::sessionBus().connect(QString(), QString("/com/qdbus/signalservice"), "com.qdbus.signalservice",
                                          "send_to_server", this, SLOT(server_get(const QString &)));
}

void Server::reply_client()
{

    // dbus-monitor --session --monitor "type='signal',interface='com.qdbus.signalclient'"
    qInfo() << "reply to client done";
    // send_to_client 为服务端定义的信号
    QDBusMessage message =
        QDBusMessage::createSignal("/com/qdbus/signalclient", "com.qdbus.signalclient", "send_to_client");
    // 发送普通消息
    // message << QString("ok, I am server，I got data");
    Reply reply;
    reply.code = 1;
    reply.message = QString("ok, I am server，I got data");
    // message << reply;  // this is a error
    message << QVariant::fromValue(reply);
    QDBusConnection::sessionBus().send(message);
}

void Server::server_get(const QString &msg)
{
    qInfo() << "Message get from client: " << msg;
    // dbus-send --session --type=signal /com/qdbus/signalclient com.qdbus.signalclient.send_to_client string:"org.deepin.demo"
    // dbus-monitor --session --monitor "type='signal',interface='com.qdbus.signalclient'"
    reply_client();
}
