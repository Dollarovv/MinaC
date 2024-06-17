#ifndef WORLD_H
#define WORLD_H

#include "entity.h"

typedef struct {
    int width;
    int height;
    Entity *entities;
    int entityCount;
} GameWorld;

void initWorld(GameWorld *world);
void runGame(GameWorld *world);
void printWorld(GameWorld *world);
void cleanupWorld(GameWorld *world);

#endif // WORLD_H
