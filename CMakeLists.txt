cmake_minimum_required(VERSION 3.17)
project(networking_demo)

set(CMAKE_CXX_STANDARD 17)

set(generatedSourcesDir ${CMAKE_BINARY_DIR}/generated)
file(MAKE_DIRECTORY "${generatedSourcesDir}")

# Disable Boost warning
set(Boost_NO_WARN_NEW_VERSIONS 1)

if (MSVC)
    # Boost asio wants this...
    add_compile_definitions("_WIN32_WINNT=0x0601")
endif ()

find_package(Boost REQUIRED COMPONENTS system)
find_package(cppzmq CONFIG)
find_package(Thrift CONFIG)

add_subdirectory(tcp)
add_subdirectory(udp)
add_subdirectory(ws)

if(cppzmq_FOUND)
    add_subdirectory(zmq)
endif ()
if (Thrift_FOUND)
    add_subdirectory(thrift)
endif ()
