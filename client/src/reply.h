#pragma once

#include <QDBusArgument>

class Reply
{
public:
    int code; ///< 状态码
    QString message; ///< 状态码对应的消息
};

inline QDBusArgument &operator<<(QDBusArgument &argument, const Reply &reply)
{
    argument.beginStructure();
    argument << reply.code << reply.message;
    argument.endStructure();
    return argument;
}
inline const QDBusArgument &operator>>(const QDBusArgument &argument, Reply &reply)
{
    argument.beginStructure();
    argument >> reply.code >> reply.message;
    argument.endStructure();
    return argument;
}

Q_DECLARE_METATYPE(Reply)