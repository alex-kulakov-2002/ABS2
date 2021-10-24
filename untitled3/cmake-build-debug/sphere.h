#ifndef __sphere__
#define __sphere__

#include <stdio.h>
#include "random.h"
#include "figure.h"
#include "exceptions.h"
#include <stdbool.h>

class Sphere : public Figure {
public:
    virtual ~Sphere() {}

    virtual void Input(FILE* inputFile);

    virtual void InputRnd();

    virtual void Output(FILE* outputFile);

    virtual double Volume();

private:
    int radious;

};

#endif
