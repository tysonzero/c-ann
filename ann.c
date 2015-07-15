#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ann.h"

void ann_create(ANN *ann) {
    int i;
    for (i = 0; i < HIDDEN; i++) {
        int j;
        for (j = 0; j < INPUTS + 1; j++) {
            ann->weights.input[i][j] = 2.0 * rand() / RAND_MAX - 1;
            ann->slopes.input[i][j] = 2.0 * rand() / RAND_MAX - 1;
        }
    }
    for (i = 0; i < ROWS - 3; i++) {
        int j;
        for (j = 0; j < HIDDEN; j++) {
            int k;
            for (k = 0; k < HIDDEN + 1; k++) {
                ann->weights.hidden[i][j][k] = 2.0 * rand() / RAND_MAX - 1;
                ann->slopes.hidden[i][j][k] = 2.0 * rand() / RAND_MAX - 1;
            }
        }
    }
    for (i = 0; i < OUTPUTS; i++) {
        int j;
        for (j = 0; j < HIDDEN + 1; j++) {
            ann->weights.output[i][j] = 2.0 * rand() / RAND_MAX - 1;
            ann->slopes.output[i][j] = 2.0 * rand() / RAND_MAX - 1;
        }
    }
}

void ann_mutate(ANN *ann, double increment) {
    int i;
    for (i = 0; i < HIDDEN; i++) {
        int j;
        for (j = 0; j < INPUTS + 1; j++) {
            ann->weights.input[i][j] += increment * ann->slopes.input[i][j]; 
            ann->slopes.input[i][j] = 2.0 * rand() / RAND_MAX - 1;
        }
    }
    for (i = 0; i < ROWS - 3; i++) {
        int j;
        for (j = 0; j < HIDDEN; j++) {
            int k;
            for (k = 0; k < HIDDEN + 1; k++) {
                ann->weights.hidden[i][j][k] += increment * ann->slopes.hidden[i][j][k]; 
                ann->slopes.hidden[i][j][k] = 2.0 * rand() / RAND_MAX - 1;
            }
        }
    }
    for (i = 0; i < OUTPUTS; i++) {
        int j;
        for (j = 0; j < HIDDEN + 1; j++) {
            ann->weights.output[i][j] += increment * ann->slopes.output[i][j];
            ann->slopes.output[i][j] = 2.0 * rand() / RAND_MAX - 1;
        }
    }
}

void ann_calculate(ANN *ann, double increment) {
    int i;
    for (i = 0; i < HIDDEN; i++) {
        int j;
        double value;
        for (j = 0, value = 0; j < INPUTS; j++) {
            value += ann->values.input[j] * (ann->weights.input[i][j] + increment * ann->slopes.input[i][j]);
        }
        value += ann->weights.input[i][INPUTS];
        ann->values.hidden[0][i] = value > 0;
    }
    for (i = 0; i < ROWS - 3; i++) {
        int j;
        for (j = 0; j < HIDDEN; j++) {
            int k;
            double value;
            for (k = 0, value = 0; k < HIDDEN; k++) {
                value += ann->values.hidden[i][k] * (ann->weights.hidden[i][j][k] + increment * ann->slopes.hidden[i][j][k]);
            }
            value += ann->weights.hidden[i][j][HIDDEN];
            ann->values.hidden[i + 1][j] = value > 0;
        }
    }
    for (i = 0; i < OUTPUTS; i++) {
        int j;
        double value;
        for (j = 0, value = 0; j < HIDDEN; j++) {
            value += ann->values.hidden[HIDDEN - 1][j] * (ann->weights.output[i][j] + increment * ann->slopes.output[i][j]);
        }
        value += ann->weights.output[i][HIDDEN];
        ann->values.output[i] = value > 0;
    }
}

void ann_save(ANN *ann, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fwrite(ann, sizeof(ANN), 1, file);
        fclose(file);
    }
}

void ann_load(ANN *ann, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        fread(ann, sizeof(ANN), 1, file);
        fclose(file);
    }
}

int main(void) {
    srand(time(NULL));
    ANN ann;
    ann_create(&ann);
    ann_load(&ann, "ann.txt");
    while (1) {
        int i;
        double increment;
        double mutation;
        for (i = 0; i < INPUTS; i++) {
            scanf("%d", &ann.values.input[i]);
        }
        scanf("%lf", &increment);
        scanf("%lf", &mutation);
        ann_calculate(&ann, increment);
        for (i = 0; i < OUTPUTS - 1; i++) {
            printf("%d ", ann.values.output[i]);
        } 
        printf("%d\n", ann.values.output[OUTPUTS - 1]);
        if (mutation) ann_mutate(&ann, mutation);
        ann_save(&ann, "ann.txt");
    }
    return 0;
}
