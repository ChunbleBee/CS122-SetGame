#include <iostream>
#include <SFML/Network.hpp>

int main(void) {
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("127.0.0.1", 53000);
    if (status != sf::Socket::Done) {
        std::cout << "Could not connect to server" << std::endl;
    }

    char buffer[100];
    std::cout << "Please enter a message to send: ";
    std::cin >> buffer;
    if (socket.send(buffer, 100) != sf::Socket::Done) {
        std::cout << "Failed to send buffer!" << std::endl;
    }

    return 0;
}