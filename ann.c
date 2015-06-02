#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INPUTS 3
#define HIDDEN 5
#define OUTPUTS 2
#define ROWS 5

typedef struct {
    double input[HIDDEN][INPUTS];
    double hidden[ROWS - 3][HIDDEN][HIDDEN];
    double output[OUTPUTS][HIDDEN];
} Links;

typedef struct {
    int input[INPUTS];
    int hidden[ROWS - 2][HIDDEN];
    int output[OUTPUTS];
} Neurons;

typedef struct {
    Links weights;
    Neurons values;
} ANN;

void ann_create(ANN *ann) {
    int i;
    for (i = 0; i < HIDDEN; i++) {
        int j;
        for (j = 0; j < INPUTS; j++) {
            ann->weights.input[i][j] = 2 * (double) rand() / RAND_MAX - 1;
        }
    }
    for (i = 0; i < ROWS - 3; i++) {
        int j;
        for (j = 0; j < HIDDEN; j++) {
            int k;
            for (k = 0; k < HIDDEN; k++) {
                ann->weights.hidden[i][j][k] = 2 * (double) rand() / RAND_MAX - 1;
            }
        }
    }
    for (i = 0; i < OUTPUTS; i++) {
        int j;
        for (j = 0; j < HIDDEN; j++) {
            ann->weights.output[i][j] = 2 * (double) rand() / RAND_MAX - 1;
        }
    }
}

int main(void)
{
    srand(time(NULL));
    return 0;
}