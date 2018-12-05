#include <iostream>
#include <SFML/Network.hpp>

int main(void) {

    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("127.0.0.1", 53002);
    if (status != sf::Socket::Done) {
        std::cout << "Could not connect to server" << std::endl;
    }

    while (true) {
        int test = 43;
        std::cin >> test;

        if (socket.send(&test, sizeof(test)) != sf::Socket::Done) {
            std::cout << "Failed to send buffer!" << std::endl;
        }
    }


    return 0;
}