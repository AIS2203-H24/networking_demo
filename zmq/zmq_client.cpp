#include <iostream>
#include <string>

#include <zmq.hpp>
#include <zmq_addon.hpp> // multipart

int main(int argc, char **argv) {

    std::string host = "localhost";
    std::string port = "4242";
    if (argc == 3) {
        // assuming <host> <port> as input
        host = argv[1];
        port = argv[2];
    }
    const std::string endpoint("tcp://" + host + ":" + port);

    // initialize the 0MQ context
    zmq::context_t context;

    // generate a push socket
    zmq::socket_type type = zmq::socket_type::push;
    zmq::socket_t socket(context, type);

    // open the connection
    std::cout << "Opening connection to " << endpoint << "..." << std::endl;
    socket.connect(endpoint);

    // send a message
    std::cout << "Sending text and a number..." << std::endl;

    std::string text{"Hello world"};
    double number = 5.6;

    socket.send(zmq::message_t(text), zmq::send_flags::sndmore);
    socket.send(zmq::message_t(&number, sizeof(number)), zmq::send_flags::none);

    std::cout << "Sent message." << std::endl;
    std::cout << "Finished." << std::endl;
}
