
#include <iostream>
#include <string>

#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>

namespace beast = boost::beast;
namespace ip = boost::asio::ip;
using tcp = boost::asio::ip::tcp;

int main() {

    try {
        auto const address = ip::make_address("0.0.0.0");
        boost::asio::ip::port_type port{8081};

        boost::asio::io_context ioc{};
        tcp::acceptor acceptor{ioc, {address, port}};
        tcp::socket socket{ioc};

        acceptor.listen(1);
        acceptor.accept(socket);

        beast::websocket::stream<beast::tcp_stream> ws{std::move(socket)};
        ws.accept();

        std::string msg{"Hello world!"};
        ws.write(boost::asio::buffer(msg));

        beast::multi_buffer buffer;
        ws.read(buffer);

        std::string message = boost::beast::buffers_to_string(buffer.data());
        std::cout << "Received: " << message << std::endl;

    } catch (const std::exception &e) {

        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
