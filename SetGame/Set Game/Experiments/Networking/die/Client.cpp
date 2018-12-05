#include "Client.hpp"

Client::Client(std::string ip_address, unsigned short port) {
    sf::Socket::Status status = socket.connect(ip_address, port);

    if (status != sf::Socket::Done) {
        exit(1);
    }

    socket.setBlocking(false);
};

Client::~Client() {

};

void Client::SendMessage(Message * message) {
    socket.send(message, sizeof(message));
};