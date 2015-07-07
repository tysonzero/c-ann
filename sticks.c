#include <stdio.h>

typedef struct {
    int hands[2][2];
    int turn;
} Sticks;

void sticks_create(Sticks *sticks) {
    sticks->hands[0][0] = 1;
    sticks->hands[0][1] = 1;
    sticks->hands[1][0] = 1;
    sticks->hands[1][1] = 1;
    sticks->turn = 0;
}

void sticks_play(Sticks *sticks, int actor, int target) {
    sticks->hands[!sticks->turn][target] += sticks->hands[sticks->turn][actor];
    sticks->turn = !sticks->turn;
}

int main(void) {
    Sticks sticks;
    sticks_create(&sticks);
    printf("%d\n", sticks.hands[0][0]);
    printf("%d\n", sticks.turn);
    sticks_play(&sticks, 0, 1);
    printf("%d\n", sticks.hands[1][1]);
    printf("%d\n", sticks.turn);
}
