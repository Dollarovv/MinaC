#include <stdio.h>
#include "world.h"

/**
 * The main function for the game.
 *
 * Initializes a new game world, runs the game loop until the user
 * enters the command "exit", and then cleans up the game world.
 *
 * @return 0 on success.
 */
int main() {
    GameWorld world;
    initWorld(&world);
    runGame(&world);
    cleanupWorld(&world);
    return 0;
}
