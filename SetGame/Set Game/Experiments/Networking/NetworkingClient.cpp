#include "NetworkingClient.h"

void NetworkingClient::RunUpdate() {

};

void NetworkingClient::RunHostUpdate() {
    sf::TcpSocket * socket = new sf::TcpSocket();

    if (server_listener.accept(*socket) == sf::Socket::Done) {
        host_sockets.push_back(socket);
    }
};

void NetworkingClient::RunClientUpdate() {

};