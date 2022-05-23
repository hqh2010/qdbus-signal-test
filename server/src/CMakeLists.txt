find_package(Qt5Core REQUIRED)
# find_package(Qt5Network REQUIRED)
find_package(Qt5DBus REQUIRED)
#find_package(PkgConfig REQUIRED)

find_package(Threads)

set(MAIN_SOURCES
        main.cpp
        server.cpp
        reply.h
        )

set(LINK_LIBS
    stdc++
    Qt5::Core
    #Qt5::Network
    Qt5::DBus
    ${CMAKE_THREAD_LIBS_INIT}
    )

add_executable(qsignal-server
        ${MAIN_SOURCES})

target_link_libraries(qsignal-server
                      PRIVATE ${LINK_LIBS})

#设置生成目标二进制的路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
install(TARGETS qsignal-server RUNTIME DESTINATION bin)