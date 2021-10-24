#include "sphere.h"


void Sphere::Input(FILE* inputFile) {
    bool isradious = ProgramException::GetInt(inputFile, &radious);
    if (isradious) {
        printf("Some values was incorrect, so they was changed to zero\n");
    }
}


void Sphere::InputRnd() {
    radious = Random::next(0, 1000);
}

void Sphere::Output(FILE* outputFile) {
    fprintf(outputFile, "It is Sphere:\n\t");
    fprintf(outputFile, "radious: %d\n\t", radious);
    fprintf(outputFile, "Volume = %f\n", Volume());
    WriteDensityInFile(outputFile);
}

double Sphere::Volume() {
    return 4.0/3*3.14159265 * radious * radious * radious;
}