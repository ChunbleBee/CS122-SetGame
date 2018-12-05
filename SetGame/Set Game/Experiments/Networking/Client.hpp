#include <SFML/Network.hpp>
#include <string>

struct Message {
    sf::Packet packet;
    std::string event_name;
};

enum MessageType {
    kHello,
    kGoodbye
};

class Client {
    sf::TcpSocket socket;
public:
    Client(std::string ip_address, unsigned short port);
    ~Client();

//    void SendMessage(std::string event_name, )
    void SendMessage(Message * message);
};