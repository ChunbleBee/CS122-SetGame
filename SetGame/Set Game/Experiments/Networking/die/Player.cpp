#include "Player.h"

Player::Player(sf::TcpSocket * socket) {
    this->socket = socket;
    //socket->setBlocking(true);
};

Player::~Player() {
    //delete this->socket;
};

std::string Player::GetName() {
    return name;
};

int Player::GetScore() {
    return score;
};

void Player::SetScore(int score) {
    this->score = score;
    socket->send(&score, kScore);
};

void Player::SetName(std::string name) {
    this->name = name;
    socket->send(name.c_str(), kPlayerName);
};

sf::TcpSocket * Player::GetSocket() {
    return socket;
};

void Player::SetSocket(sf::TcpSocket * socket) {
    this->socket = socket;
};

void Player::RunNetworkUpdate() {
    exit(1);

    char buffer[512];
    size_t buffer_size;
    if (socket->receive(&buffer, sizeof(buffer), buffer_size) == sf::Socket::Done) {
        std::cout << "data\t" << *buffer << std::endl;
        switch (buffer_size) {
            case kPlayerName:
                SetName(buffer);
                break;
        }
    }
};