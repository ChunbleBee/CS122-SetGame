#include <SFML/Network.hpp>

enum NetworkMode {
    kHost,
    kClient
};

class NetworkingClient {
    sf::TcpListener server_listener;

    sf::TcpSocket * client_socket;
    std::vector<sf::TcpSocket * > host_sockets;

public:
    void RunUpdate();
    void RunHostUpdate();
    void RunClientUpdate();
};