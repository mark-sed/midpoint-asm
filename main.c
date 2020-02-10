#include "midpoint.h"
#include <stdlib.h>
#include <stdint.h>

void put8lines(uint8_t **bitmap, long s1, long s2, long y, long x){
    for(long offs = s2 - y; offs < s2 + y + 1; offs++){
        bitmap[s1 + x][offs] = PIXEL_DRAWN;
        bitmap[s1 - x][offs] = PIXEL_DRAWN;
    }
    

    for(long offs = s2 - x; offs < s2 + x ; offs++){
        bitmap[s1 + y][offs] = PIXEL_DRAWN;
        bitmap[s1 - y][offs] = PIXEL_DRAWN;
    }

}

int main(int argc, char *argv[]){
    uint8_t **bmap;
    bmap = malloc(WIDTH * sizeof(uint8_t *));
    for(long i = 0; i < WIDTH; i++){
        bmap[i] = malloc(HEIGHT * sizeof(uint8_t));
    }
    

    midpoint(bmap, WIDTH/2, HEIGHT/2, WIDTH/2-2);
    
    
    for(int x = 0; x < WIDTH; x++){
        for(int y = 0; y < HEIGHT; y++){
            printf("%c ", bmap[x][y] ? 'o' : '_');
        }
        printf("\n");
    }

    for(long i = 0; i < WIDTH; i++){
        free(bmap[i]);
    }
    free(bmap);
    return 0;
}
