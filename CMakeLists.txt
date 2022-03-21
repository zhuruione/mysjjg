cmake_minimum_required(VERSION 3.19)
project(sjjg)

set(CMAKE_CXX_STANDARD 14)

add_executable(sjjg main.cpp)
add_executable(arraylist list/arraylist.cpp)
add_executable(linklist list/Linklist.cpp)
add_executable(stack stack/stack.cpp)
add_executable(arrayqueue Queue/arayqueue.cpp)
add_executable(linkqueue Queue/Linkqueue.cpp)
add_executable(graph graph/Graph.cpp)
add_executable(housewark homework/housewark.cpp)
add_executable(string string/string.cpp)
add_executable(tree tree/Tree.cpp)
add_executable(zjcr paixu/zhujiecharu.cpp)
add_executable(mpbx paixu/maopaopaixu.cpp)
add_executable(kuohao
        homework/kuohao.cpp
        tool/tools.cpp
        tool/tools.h)