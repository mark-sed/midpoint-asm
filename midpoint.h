#ifndef _MIDPOINT_H_
#define _MIDPOINT_H_

#include <stdint.h>

#define PIXEL_DRAWN 1
#define PIXEL_EMPTY 0
#define WIDTH 12800
#define HEIGHT 12800

void midpoint(uint8_t **midpoint, long s1, long s2, long r);

#endif //_MIDPOINT_H_
