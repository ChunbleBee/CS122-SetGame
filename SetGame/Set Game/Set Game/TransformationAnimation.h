#include <SFML/Graphics.hpp>
#include "AnimationTimer.h"

class TransformationAnimation {
    sf::Transformable * transformable;

    AnimationTimer<sf::Vector2f> transformation;
    AnimationTimer<sf::Vector2f> scaling;
    AnimationTimer<float>        rotation;

public:
    TransformationAnimation(sf::Transformable * transformable);
    ~TransformationAnimation();

    void RunUpdate();

    void TimedTransform(sf::Vector2f vector, float transform_time_ms, MovementMode mode);
    void TimedScale(sf::Vector2f scale_factor, float scale_time_ms, MovementMode mode);
    void TimedRotate(float rotate_amount, float rotate_time_ms, MovementMode mode);
};