#pragma once
#include "RigidBody.h"
#include "Vector2D.h"
#include <vector>

class World {
    private:
        std::vector<RigidBody> rigidBodies{};

    public:

    void addBody(const RigidBody& body);
    RigidBody& getBody(int index);
    void gravity();
    void collisionDetection();
    void collisionResolution();

    // for loop to handle collision detection
};