
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <thread>

#include "server.h"

#include "reply.h"

int main(int argc, char **argv)
{
    QCoreApplication a(argc, argv);
    qSetMessagePattern("%{time yyyy-MM-dd hh:mm:ss.zzz} [%{appname}] [%{type}] %{message}");
    
    // qRegisterMetaType<Reply>("Reply");
    qDBusRegisterMetaType<Reply>();

    Server server;

    // std::thread th1(server_listen);
    // th1.detach();

    return a.exec();
}