#include <Cstructs.h>

PosDim createPosDim(int32_t x, int32_t y, uint32_t w, uint32_t h){
    PosDim posdim = {x, y, w, h};
    return posdim;
}

RowCollumn createRowCollumn(uint32_t rows, uint32_t collumns){
    RowCollumn rowcollumn;
    rowcollumn.r = rows;
    rowcollumn.c = collumns;
    return rowcollumn;
}