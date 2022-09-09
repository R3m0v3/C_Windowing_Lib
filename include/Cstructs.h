#ifndef CStructs_H
#define CStructs_H

#include <stdint.h>


//POSDIM
typedef struct __PosDim{
    int32_t x, y;
    uint32_t w, h;
}PosDim;

/*
Returns a PosDim struct with the given parameters or NULL if it failes
@param x: x coordinate on screen
@param y: y coordinate on screen
@param w: current width
@param h: current height
*/
PosDim createPosDim(int32_t x, int32_t y, uint32_t w, uint32_t h);

//ROWCOLLUMN
typedef struct __RowCollumn{
  uint32_t r, c;
}RowCollumn;

/*
Returns a RowCollumn struct with the given parameters
@param uint32_t rows: count of rows in this struct
@param uint32_t collumns: count of collumns in this struct
*/
RowCollumn createRowCollumn(uint32_t rows, uint32_t collumns);

#endif