#include "RigidBody.h"

RigidBody::RigidBody(float mass, float bounciness, RGBA color, Vector2D position, Vector2D dimensions, Vector2D velocity) : 
    mass{mass},
    bounciness{bounciness},
    color{color},
    position{position},
    dimensions(dimensions),
    velocity{velocity} {
    }

const RGBA RigidBody::getColor() const {
    return color;
}

const Vector2D RigidBody::getPosition() const {
    return position;
}

const Vector2D RigidBody::getVelocity() const {
    return velocity;
}

const Vector2D RigidBody::getDimensions() const {
    return dimensions;
}

void RigidBody::pushVelocity(const Vector2D &other) {
    position += other;
}
