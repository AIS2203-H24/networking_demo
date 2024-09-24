#include <iostream>
#include <string>

#include <zmq.hpp>
#include <zmq_addon.hpp>

int main(int argc, char **argv) {

    std::string port = "4242";
    if (argc == 2) {
        // assuming <port> as input
        port = argv[1];
    }

    const std::string endpoint("tcp://*:" + port);

    // initialize the 0MQ context
    zmq::context_t context;

    // generate a pull socket
    zmq::socket_type type = zmq::socket_type::pull;
    zmq::socket_t socket(context, type);

    // bind to the socket
    std::cout << "Binding to " << endpoint << "..." << std::endl;
    socket.bind(endpoint);

    // receive the message
    std::cout << "Receiving message..." << std::endl;

    zmq::message_t message;
    // decompose the message

    if (auto result = socket.recv(message)) {
        auto text = message.to_string();
        std::cout << "Received text: \"" << text << "\"" << std::endl;
    }

    if (auto result = socket.recv(message)) {
        double number = *message.data<double>();
        std::cout << "Received number: " << number << std::endl;
    }

    std::cout << "Finished." << std::endl;
}
