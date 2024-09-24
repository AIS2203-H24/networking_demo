
add_executable(zmq_server zmq_server.cpp)
target_link_libraries(zmq_server PRIVATE cppzmq)

add_executable(zmq_client zmq_client.cpp)
target_link_libraries(zmq_client PRIVATE cppzmq)
