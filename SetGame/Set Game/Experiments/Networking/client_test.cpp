#include <iostream>
#include <SFML/Network.hpp>
#include "Client.hpp"

int main(void) {

    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("127.0.0.1", 53002);
    if (status != sf::Socket::Done) {
        std::cout << "Could not connect to server" << std::endl;
    }

    Message * buffer = new Message();

    buffer->packet << "f5nt5stic test";
    buffer->event_name = "test_event";

    if (socket.send(buffer, sizeof(buffer)) != sf::Socket::Done) {
        std::cout << "Failed to send buffer!" << std::endl;
    }

    return 0;
}