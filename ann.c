#include <stdio.h>

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
    Links weights;
} ANN;

int main(void)
{
    return 0;
}
