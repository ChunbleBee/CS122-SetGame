#include <SFML/Graphics.hpp>
#include <math.h>

#include <iostream>

#define M_PI 3.1415926536

enum MovementMode {
    kLinear,
    kBounce
};

template <class T>
class AnimationTimer {
    MovementMode movement_mode;

    T start;
    T end;
    float total_time_ms;
    sf::Clock clock;

    T CalculateLinearMovement() {
        float elasped_time = clock.getElapsedTime().asMilliseconds();
        return start + (end - start) * (elasped_time / total_time_ms);
    };

    T CalculateBounceMovement() {
        float bounce_time_percentage = 0.10f;
        float elasped_time = clock.getElapsedTime().asMilliseconds();
        float bounce_time_starts = total_time_ms - (total_time_ms * bounce_time_percentage);

        //Calculate the bounce
        float bounce_amplitude_multiplier = 0.05f;
        float bounce_percentage = (elasped_time - bounce_time_starts) / (total_time_ms * bounce_time_percentage);


        if (elasped_time >= bounce_time_starts) {
            //It's bounce time motherfucker
            bounce_amplitude_multiplier *= 1.0f - bounce_percentage;
            return end + (start - end) * sin(bounce_percentage * (float)M_PI) * bounce_amplitude_multiplier;
        } else {
            return start + (end - start) * (elasped_time / bounce_time_starts);
        }
    };


public:
    AnimationTimer() {
    };

    AnimationTimer(T start, T end, float duration) {
        this->Set(start, end, duration);
    };

    AnimationTimer(T start, T end, float duration, MovementMode mode) {
        this->Set(start, end, duration, mode);
    };

    void Set(T start, T end, float duration) {
        this->Set(start, end, duration, kLinear);
    };

    void Set(T start, T end, float duration, MovementMode mode) {
        this->start = start;
        this->end = end;
        this->total_time_ms = duration;
        this->movement_mode = mode;
    };


    T GetPosition() {
        float elasped_time = clock.getElapsedTime().asMilliseconds();

        if (elasped_time >= total_time_ms) {
            return end;
        }


        switch (movement_mode) {
            default: 
            case kLinear:
                return CalculateLinearMovement();
                break;

            case kBounce:
                return CalculateBounceMovement();
                break;
        }
    };
};