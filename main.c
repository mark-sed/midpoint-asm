#include "midpoint.h"
#include <stdlib.h>

int main(int argc, char *argv[]){
    TData **bmap;
    bmap = malloc(WIDTH * sizeof(TData));
    for(long i = 0; i < WIDTH; i++){
        bmap[i] = malloc(HEIGHT * sizeof(TData));
    }

    midpoint(bmap, WIDTH/2, HEIGHT/2, WIDTH/3);
    
    /*
    for(int x = 0; x < WIDTH; x++){
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
