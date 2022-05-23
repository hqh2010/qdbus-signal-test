# 说明

This is a demo for qdbus-signal.

使用qdbus signal 传递自定义结构体数据。

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
