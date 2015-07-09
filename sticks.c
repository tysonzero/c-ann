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

void sticks_play(Sticks *sticks, int attack, int x, int y) {
    if (attack) {
        sticks->hands[!sticks->turn][y] += sticks->hands[sticks->turn][x];
        if (sticks->hands[!sticks->turn][y] >= 5) {
            sticks->hands[!sticks->turn][y] = 0;
        }
    } else {
        int fingers = sticks->hands[sticks->turn][0] + sticks->hands[sticks->turn][1];
        int desired = 2 * x + y;
        if (desired > fingers) desired = fingers;
        if (desired < fingers - 4) desired = fingers - 4;
        sticks->hands[sticks->turn][0] = desired;
        sticks->hands[sticks->turn][1] = fingers - desired;
    }
    sticks->turn = !sticks->turn;
}

int main(void) {
    Sticks sticks;
    sticks_create(&sticks);
    printf("%d\n", sticks.hands[0][0]);
    printf("%d\n", sticks.turn);
    sticks_play(&sticks, 0, 0, 0);
    printf("%d\n", sticks.hands[0][0]);
    printf("%d\n", sticks.hands[0][1]);
    printf("%d\n", sticks.turn);
}
