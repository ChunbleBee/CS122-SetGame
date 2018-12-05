#include "Networking.h"

NetworkingClient::NetworkingClient(NetworkingMode mode) {
    if (mode == kHost) {
        listener.listen(53002);
    } else {
        this_player = new Player(new sf::TcpSocket());
    }
};

NetworkingClient::~NetworkingClient() {
    //delete this_player;
};

bool NetworkingClient::StartClient(std::string ip_address) {
    this->this_player->GetSocket()->connect(ip_address, 53002);

    return true;
};

void NetworkingClient::RunUpdate() {
    if (mode == kHost) {
        Player new_player(new sf::TcpSocket());
        if (listener.accept(*new_player.GetSocket()) == sf::Socket::Done) {
            players.push_back(new_player);
        }

        for (Player player : players) {
            player.RunNetworkUpdate();
        }
    }

    if (mode == kClient) {
        this->this_player->RunNetworkUpdate();
    }
};

Player * NetworkingClient::GetPlayer() {
    return this_player;
}

std::vector<Player> * NetworkingClient::GetPlayers() {
    return &players;
}