#include <iostream>
#include <SFML/Network.hpp>
#include "Client.hpp"

int main(void) {
    sf::TcpListener listener;

    if (listener.listen(53002) != sf::Socket::Done) {
        std::cout << "Error getting port" << std::endl;
    }

    sf::TcpSocket client;
    if (listener.accept(client) != sf::Socket::Done) {
        std::cout << "Error getting client" << std::endl;
    }


    while (true) {
        int test;
        size_t size;
        if (client.receive(&test, sizeof(test), size) != sf::Socket::Done) {
            std::cout << "Error getting data" << std::endl;
        }
         std::cout << "Got test: " << test << std::endl;
    }

    return 0;
}