#pragma once

struct Vector2D {
    float x{};
    float y{};

    Vector2D operator+=(const Vector2D& other) {
        return Vector2D(this->x += other.x, this->y += other.y);
    };

};