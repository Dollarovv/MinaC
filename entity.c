#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entity.h"

void addEntity(GameWorld *world, const char *name, int x, int y) {
    world->entities = realloc(world->entities, sizeof(Entity) * (world->entityCount + 1));
    strcpy(world->entities[world->entityCount].name, name);
    world->entities[world->entityCount].x = x;
    world->entities[world->entityCount].y = y;
    world->entityCount++;
}

void moveEntity(GameWorld *world, int entityIndex, const char *direction) {
    if (entityIndex < 0 || entityIndex >= world->entityCount) return;

    Entity *entity = &world->entities[entityIndex];
    if (strcmp(direction, "up") == 0 && entity->y > 0) {
        entity->y--;
    } else if (strcmp(direction, "down") == 0 && entity->y < world->height - 1) {
        entity->y++;
    } else if (strcmp(direction, "left") == 0 && entity->x > 0) {
        entity->x--;
    } else if (strcmp(direction, "right") == 0 && entity->x < world->width - 1) {
        entity->x++;
    } else {
        printf("Invalid move!\n");
    }
}
