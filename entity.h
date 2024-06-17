#ifndef ENTITY_H
#define ENTITY_H

#include "world.h"

typedef struct {
    char name[20];
    int x;
    int y;
} Entity;

void addEntity(GameWorld *world, const char *name, int x, int y);
void moveEntity(GameWorld *world, int entityIndex, const char *direction);

#endif // ENTITY_H
