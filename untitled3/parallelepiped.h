#ifndef __parallelepiped__
#define __parallelepiped__

#include <stdio.h>
#include "random.h"
#include "figure.h"
#include "exceptions.h"
#include <stdbool.h>

class Parallelepiped : public Figure{
public:
    virtual ~Parallelepiped() {}

    virtual void Input(FILE* inputFile);

    virtual void InputRnd();

    virtual void Output(FILE* outputFile);

    virtual double Volume();

private:
    int side1;
    int side2;
    int side3;

};

#endif


