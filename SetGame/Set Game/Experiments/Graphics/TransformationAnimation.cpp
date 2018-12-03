#include "Animation.hpp"

Animation::Animation(sf::Transformable * transformable) {
    this->transformable = transformable;

    TimedTransform(transformable->getPosition(), 0.0f, kLinear);
    TimedScale(transformable->getScale(), 0.0f, kLinear);
    TimedRotate(transformable->getRotation(), 0.0f, kLinear);
};

Animation::~Animation() {};

void Animation::TimedTransform(sf::Vector2f vector, float transform_time_ms, MovementMode mode) {
    this->transformation.Set(
        transformable->getPosition(),
        vector,
        transform_time_ms,
        mode
    );
};

void Animation::TimedScale(sf::Vector2f vector, float transform_time_ms, MovementMode mode) {
    this->scaling.Set(
        transformable->getScale(),
        vector,
        transform_time_ms,
        mode
    );
};

void Animation::TimedRotate(float vector, float transform_time_ms, MovementMode mode) {
    this->rotation.Set(
        transformable->getRotation(),
        vector,
        transform_time_ms,
        mode
    );
};

void Animation::RunUpdate() {
    transformable->setPosition(transformation.GetPosition());
    transformable->setScale(scaling.GetPosition());
    transformable->setRotation(rotation.GetPosition());
};