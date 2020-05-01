/**
 * @file main.c
 * @author Marek Sedláček
 * @date February 2020
 * 
 * @brief File for testing performance of midpoint
 * module implementation.
 * 
 * This code was made for my bachelor's thesis at
 * Brno University of Technology
 */

#include "midpoint.h"
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[]){
    uint8_t **bmap;
    bmap = malloc(WIDTH * sizeof(uint8_t *));
    for(long i = 0; i < WIDTH; i++){
        bmap[i] = malloc(HEIGHT * sizeof(uint8_t));
    }

    midpoint(bmap, WIDTH/2, HEIGHT/2, 7680/2);

    for(long i = 0; i < WIDTH; i++){
        free(bmap[i]);
    }
    free(bmap);
    return 0;
}
