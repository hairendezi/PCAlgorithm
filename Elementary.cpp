#include "Elementary.h"

void Rule5::printRule() {
    printf("%u:%u/%d  %u:%u/%d  %d:%d  %d:%d  %d:%d\n",
           range[0][0], range[0][1], mask[0],
           range[1][0], range[1][1], mask[1],
           range[2][0], range[2][1],
           range[3][0], range[3][1],
           range[4][0], range[4][1]);
}