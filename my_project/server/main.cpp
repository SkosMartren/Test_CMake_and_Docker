#include <iostream>
#include <boost/asio.hpp>

int main() {
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::acceptor acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 12345));

    while (true) {
        boost::asio::ip::tcp::socket socket(io_context);
        acceptor.accept(socket);

        std::string message = "Hello from server!\n";

        boost::system::error_code ignored_error;
        boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
        std::cout << "\nEnd server";
    }

    return 0;
}
