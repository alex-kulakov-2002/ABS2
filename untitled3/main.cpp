#include <string.h>
#include "container.h"
#include "time.h"
#include "exceptions.h"
#include "testGenerator.h"


int main(int argc, char* argv[]) {
    if (argc == 3 && !strcmp(argv[1], "-g")) {
        int size = strtol(argv[2], &argv[2], 0);
        if ((size < 1) || (size > 10000)) {
            printf("incorrect number of figures = %d. Set 0 < number <= 10000\n", size);
            return 4;
        }
        TestGeneretor::generateTest(size);
        printf("Test generated successful!\n");
        return 5;
    }

    clock_t time_start = clock();

    // Обработка некорректного количества аргументов.
    if (argc != 5) {
        ProgramException::errMessage1();
        return 1;
    }

    printf("Start\n");
    Container c;


    if (!strcmp(argv[1], "-f")) {
        FILE* inputFile = fopen(argv[2], "r");
        if (inputFile == NULL) {
            printf("Incorrect input file");
            printf(argv[2]);
            return 6;
        }
        c.Input(inputFile);
    }
    else if (!strcmp(argv[1], "-n")) {
        int size = strtol(argv[2], &argv[2], 0);
        if ((size < 1) || (size > 10000)) {
            printf("incorrect number of figures = %d. Set 0 < number <= 10000\n", size);
            return 3;
        }


        srand(time(NULL));
        // Заполнение контейнера генератором случайных чисел
        c.InputRnd(size);
    }
    else {
        ProgramException::errMessage2();
        return 2;
    }


    // Открытие первого файла для записи.
    FILE* outputFile1;
    if (!(outputFile1 = fopen(argv[3], "w+"))) {
        perror("Невозможно открыть файл");
        exit(EXIT_FAILURE);
    }

    // Вывод содержимого контейнера в файл
    fprintf(outputFile1, "Filled container:\n");
    c.Output(outputFile1);
    fclose(outputFile1);

    // Открытие второго файла для записи.
    FILE* outputFile2;
    if (!(outputFile2 = fopen(argv[4], "w+"))) {
        perror("Невозможно открыть файл");
        exit(EXIT_FAILURE);
    }

    // Вывод результатов выполнения дополнительной функции и содержимого измененного контейнера в файл.
    fprintf(outputFile2, "Volume average = %f\n", c.GetAverageVolume());
    fprintf(outputFile2, "Changed container:\n");
    c.ShiftByVolume();
    c.Output(outputFile2);
    fclose(outputFile2);

    printf("Stop\n");
    printf("Seconds: %f\n", ((double)(clock() - time_start)) / CLOCKS_PER_SEC);
    return 0;
}
