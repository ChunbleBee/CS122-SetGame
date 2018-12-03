#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Animation.hpp"

void WindowEventRunner(sf::RenderWindow * window) {
    sf::Event window_event;
    while (window->pollEvent(window_event)) {
        if (window_event.type == sf::Event::Closed) {
            window->close();
        }

        if (window_event.type == sf::Event::KeyPressed && window_event.key.code == sf::Keyboard::Escape) {
            window->close();
        }
    }
}

void RenderLoop (sf::RenderWindow * window, bool * should_run) {
    sf::Font font;
    if (!font.loadFromFile("./Hasklig-Regular.otf")) {
        window->close();
        return;
    }

    /*
    sf::Text text;

    text.setFont(font);
    text.setString("Hello World");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);

    */

    sf::Texture head;
    head.loadFromFile("./head.png");
    sf::Sprite head_sprite;
    head_sprite.setTexture(head);

    TransformationAnimation test_transform(&head_sprite);

    sf::Vector2f test_cords(400, 400);
    sf::Vector2f test_scale(0.5f, 0.5f);

    test_transform.TimedTransform(test_cords, (3 * 1000), kLinear);
    test_transform.TimedRotate(90.0f, 3000, kLinear);
    test_transform.TimedScale(test_scale, 3000, kLinear);

    sf::Clock clock;
    while (window->isOpen()) {
        WindowEventRunner(window);
        window->clear(sf::Color::Black);

        window->draw(head_sprite);

        test_transform.RunUpdate();


        window->display();

        sf::sleep(sf::milliseconds(16));
    }
}

int main(void) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "OpenGL");
    bool should_render = true;

    RenderLoop(&window, &should_render);

    return 0;
}