#ifndef __random__
#define __random__

#include <stdlib.h>
#include "stdint.h"

class Random {
public:
    static int next(int lower = 0, int upper = INT32_MAX);
};

#endif