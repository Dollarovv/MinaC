#include <stdio.h>
#include <stdlib.h>
#include "world.h"
#include "entity.h"

/**
 * Initializes a new game world.
 *
 * @param world The world to initialize.
 */
void initWorld(GameWorld *world) {
    world->width = 10;
    world->height = 10;
    world->entities = NULL;
    world->entityCount = 0;

    // Add a player
    addEntity(world, "Player", 0, 0);
    // Add an NPC
    addEntity(world, "NPC", 5, 5);
}


/**
 * Runs the game loop.
 *
 * This function will enter a loop where it prints the current state of the
 * game world, prompts the user for a command, and executes the command if
 * valid. The loop continues until the user enters the command "exit".
 *
 * @param world The game world to run.
 */
void runGame(GameWorld *world) {
    char command[10];
    while (1) {
        printWorld(world);
        printf("Enter command (move <direction> or exit): ");
        scanf("%s", command);
        
        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "move") == 0) {
            char direction[10];
            scanf("%s", direction);
            moveEntity(world, 0, direction); // Move the player
        }
    }
}


void printWorld(GameWorld *world) {
/*************  ✨ Codeium Command ⭐  *************/
/**
 * Prints a visual representation of the game world to the console.
 *
 * @param world The world to print.
 */
/******  14fddcce-7439-466d-9a49-5073d7674e4a  *******/    printf("Game World (%dx%d):\n", world->width, world->height);
    for (int y = 0; y < world->height; y++) {
        for (int x = 0; x < world->width; x++) {
            int found = 0;
            for (int i = 0; i < world->entityCount; i++) {
                if (world->entities[i].x == x && world->entities[i].y == y) {
                    printf("%s ", world->entities[i].name);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void cleanupWorld(GameWorld *world) {
    free(world->entities);
}
