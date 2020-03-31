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
    
    
    /*for(int x = 0; x < WIDTH; x++){
        for(int y = 0; y < HEIGHT; y++){
            printf("%c ", bmap[x][y] ? 'o' : '_');
        }
        printf("\n");
    }*/

    for(long i = 0; i < WIDTH; i++){
        free(bmap[i]);
    }
    free(bmap);
    return 0;
}
