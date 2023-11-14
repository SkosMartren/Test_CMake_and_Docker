#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>

int main() {
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::resolver resolver(io_context);
    boost::asio::ip::tcp::resolver::results_type endpoints = resolver.resolve("localhost", "12345");

    boost::asio::ip::tcp::socket socket(io_context);
    boost::asio::connect(socket, endpoints);

    boost::array<char, 128> recv_buf;
    boost::system::error_code error;

    size_t len = socket.read_some(boost::asio::buffer(recv_buf), error);

    if (error == boost::asio::error::eof) {
        std::cout << "Connection closed by server.\n";
    } else if (error) {
        throw boost::system::system_error(error); // Some other error.
    }

    std::cout.write(recv_buf.data(), len);
    std::cout << "\nEnd client";
    return 0;
}
