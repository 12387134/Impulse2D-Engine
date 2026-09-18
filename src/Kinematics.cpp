#include "Kinematics.h"

void World::addBody(const RigidBody& body) {
    rigidBodies.push_back(body);
}

void World::gravity() {}
void World::collisionResolution() {}
void World::collisionDetection() {}
RigidBody& World::getBody(int index) {
    return rigidBodies.at(index);
}