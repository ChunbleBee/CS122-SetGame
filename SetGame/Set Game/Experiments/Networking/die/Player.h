#include <iostream>
#include <string>
#include <SFML/Network.hpp>
#include "PacketTypes.h"

class Player {
    std::string name;
    int score;

    sf::TcpSocket * socket;

public:
    Player(sf::TcpSocket * socket);
    ~Player();

    std::string GetName();
    int GetScore();

    void SetScore(int score);
    void SetName(std::string name);

    sf::TcpSocket * GetSocket();
    void SetSocket(sf::TcpSocket * socket);

    void RunNetworkUpdate();
};