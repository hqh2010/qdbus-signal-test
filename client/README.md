# 说明

This is a demo for qdbus-signal.

使用qdbus signal 传递自定义结构体数据。

注意：

qdbus 如果在xml中定义信号，则信号参数方向为 out

<signal name="uninstallStatusChange">
    <arg name="reply" type="(is)" direction="out"/>
    <annotation name="org.qtproject.QtDBus.QtTypeName.Out0" value="linglong::service::Reply"/>
</signal>

# 使用方式

cd client

mkdir build

cd build

cmake ..

make -j8

# 运行

开两个终端

qsignal-server

qsignal-client

# 清理

make clean

# 参考文档

https://www.jianshu.com/p/10bf5d27dcfc

https://blog.csdn.net/czhzasui/article/details/81071383

https://www.qtcentre.org/threads/26871-Problems-with-marshalling-a-struct-to-Qt-DBus

https://www.jianshu.com/p/438c9d2594f1
