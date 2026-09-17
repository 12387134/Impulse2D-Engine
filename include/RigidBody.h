#include "Vector2D.h"

class RigidBody {
    private:
        Vector2D position{};
        Vector2D dimensions{};
        Vector2D velocity{};
        float mass{};
        float bounciness{};

    public:
        RigidBody(float mass, float bounciness, Vector2D position, Vector2D dimensions, Vector2D velocity) : 
            mass{mass},
            bounciness{bounciness},
            position{position},
            dimensions(dimensions),
            velocity{velocity} {
            }

        //~RigidBody();
};