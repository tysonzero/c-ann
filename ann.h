#ifndef ANN_H
#define ANN_H

#define INPUTS 3
#define HIDDEN 5
#define OUTPUTS 2
#define ROWS 5

typedef struct {
    double input[HIDDEN][INPUTS + 1];
    double hidden[ROWS - 3][HIDDEN][HIDDEN + 1];
    double output[OUTPUTS][HIDDEN + 1];
} Links;

typedef struct {
    int input[INPUTS];
    int hidden[ROWS - 2][HIDDEN];
    int output[OUTPUTS];
} Neurons;

typedef struct {
    Links weights;
    Links slopes;
    Neurons values;
} ANN;

void ann_create(ANN *ann);

void ann_mutate(ANN *ann, double increment);

void ann_calculate(ANN *ann, double increment);

void ann_save(ANN *ann, char *filename);

void ann_load(ANN *ann, char *filename);

void ann_print(ANN *ann);

#endif
