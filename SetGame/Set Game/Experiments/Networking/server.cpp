#include <iostream>
#include <SFML/Network.hpp>

int main(void) {
    sf::TcpListener listener;

    if (listener.listen(53000) != sf::Socket::Done) {
        std::cout << "Error getting port" << std::endl;
    }

    sf::TcpSocket client;
    if (listener.accept(client) != sf::Socket::Done) {
        std::cout << "Error getting client" << std::endl;
    }

    std::cout << "Got a client!!" << std::endl;

    char buffer[100];
    size_t size;
    if (client.receive(buffer, 100, size) != sf::Socket::Done) {
        std::cout << "Error getting data" << std::endl;
    }

    std::cout << "Got data!! Size: " << size << std::endl;
    std::cout << buffer << std::endl;

    return 0;
}