#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ann.h"

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
        ann_print(&ann);
        if (mutation) ann_mutate(&ann, mutation);
        ann_save(&ann, "ann.txt");
    }
    return 0;
}
