#include <stdio.h>

typedef struct {
    int fingers[2][2];
    int turn;
} Chopsticks;

void chopsticks_create(Chopsticks *chopsticks) {
    chopsticks->fingers[0][0] = 1;
    chopsticks->fingers[0][1] = 1;
    chopsticks->fingers[1][0] = 1;
    chopsticks->fingers[1][1] = 1;
    chopsticks->turn = 0;
}

int main(void) {
    Chopsticks chopsticks;
    chopsticks_create(&chopsticks);
    printf("%d\n", chopsticks.fingers[0][0]);
    printf("%d\n", chopsticks.turn);
}
