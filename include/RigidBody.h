#pragma once
#include "Vector2D.h"
#include "rgba.h"

class RigidBody {
    private:
        Vector2D position{};
        Vector2D dimensions{};
        Vector2D velocity{};
        RGBA color{};
        float mass{};
        float bounciness{};

    public:
        RigidBody(float mass, float bounciness, RGBA color, Vector2D position, Vector2D dimensions, Vector2D velocity);
        
        const Vector2D getPosition() const;
        const Vector2D getDimensions() const;
        const Vector2D getVelocity() const;
        const RGBA getColor() const;

        void pushVelocity(const Vector2D &other);

};