#include <stdio.h>

typedef struct {
    int fingers[2][2];
    int turn;
} Sticks;

void sticks_create(Sticks *sticks) {
    sticks->fingers[0][0] = 1;
    sticks->fingers[0][1] = 1;
    sticks->fingers[1][0] = 1;
    sticks->fingers[1][1] = 1;
    sticks->turn = 0;
}

int main(void) {
    Sticks sticks;
    sticks_create(&sticks);
    printf("%d\n", sticks.fingers[0][0]);
    printf("%d\n", sticks.turn);
}
