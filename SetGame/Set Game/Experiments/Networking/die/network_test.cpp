#include <iostream>
#include "Networking.h"

void RunHost () {
    NetworkingClient * host = new NetworkingClient(kHost);

    while (true) {
        host->RunUpdate();

        std::cout << "Connected Players:" << std::endl;
        for (Player player : *host->GetPlayers()) {
            std::cout << player.GetName() << "\t" << player.GetScore() << std::endl;
        }
    }

}

void RunClient () {
    NetworkingClient * client = new NetworkingClient(kClient);

    client->StartClient("127.0.0.1");

    std::cout << "PLease enter a player name: ";

    std::string new_name;
    std::cin >> new_name;

    client->GetPlayer()->SetName(new_name);


    while (true) {
        int score = 0;
        std::cin >> score;
        client->GetPlayer()->SetScore(score);
        std::cout << std::endl;
        client->RunUpdate();
    }
}

int main(void) {
    std::cout << "0 host 1 client" << std::endl;

    int ans;
    std::cin >> ans;

    if (ans == 0) {
        RunHost();
    }

    if (ans == 1) {
        RunClient();
    }
}