#include <SFML/Network.hpp>
#include "Player.h"

enum NetworkingMode {
    kHost,
    kClient
};


class NetworkingClient {
    NetworkingMode mode;
    Player * this_player;

    sf::TcpListener listener;

    std::vector<Player> players;
public:
    NetworkingClient(NetworkingMode mode);
    ~NetworkingClient();

    bool StartClient(std::string ip_address);
    void RunUpdate();

    Player * GetPlayer();
    std::vector<Player> * GetPlayers();
};