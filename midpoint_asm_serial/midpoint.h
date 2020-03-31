#ifndef _MIDPOINT_H_
#define _MIDPOINT_H_

#include <stdint.h>

#define PIXEL_DRAWN 1
#define PIXEL_EMPTY 0
#define WIDTH 8000
#define HEIGHT 8000

void midpoint(uint8_t **midpoint, long s1, long s2, long r);

#endif //_MIDPOINT_H_
