
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <thread>

#include "client.h"

#include "reply.h"

void client_send()
{
    while (true) {
        qInfo() << "client message send";
        // 发送客户端自己定义的send_to_server信号
        QDBusMessage message =
            QDBusMessage::createSignal("/com/qdbus/signalservice", "com.qdbus.signalservice", "send_to_server");
        message << QString("Hello, I am client");
        QDBusConnection::sessionBus().send(message);
        getchar();
    }
}

int main(int argc, char **argv)
{
    QCoreApplication a(argc, argv);
    qSetMessagePattern("%{time yyyy-MM-dd hh:mm:ss.zzz} [%{appname}] [%{type}] %{message}");

    // qRegisterMetaType<Reply>("Reply");
    qDBusRegisterMetaType<Reply>();

    Client client;
    std::thread jobThread(client_send);
    jobThread.detach();

    return a.exec();
}