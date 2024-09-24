
add_executable(tcp_server tcp_server.cpp)
target_link_libraries(tcp_server PRIVATE Boost::system)

add_executable(tcp_client tcp_client.cpp)
target_link_libraries(tcp_client PRIVATE Boost::system)
