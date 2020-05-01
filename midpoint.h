/**
 * @file midpoint.h
 * @author Marek Sedláček
 * @date February 2020
 * 
 * @brief Header file for midpoint module
 * 
 * This code was made for my bachelor's thesis at
 * Brno University of Technology
 */

#ifndef _MIDPOINT_H_
#define _MIDPOINT_H_

#include <stdint.h>

#define PIXEL_DRAWN 1
#define PIXEL_EMPTY 0
#define WIDTH 7860
#define HEIGHT 7860

/**
 * Function for creating filled circle in an image
 * @param midpoint image
 * @param s1 circle's middle position on the x axis
 * @param s2 circle's middle position on the y axis
 * @param r circle's radius
 */
void midpoint(uint8_t **midpoint, long s1, long s2, long r);

#endif //_MIDPOINT_H_
