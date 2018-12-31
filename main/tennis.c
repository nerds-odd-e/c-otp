#include <stdio.h>
#include "tennis.h"

int playerOnePoint = 0;
int playerTwoPoint = 0;

const char *scoreTexts[4] = {"Love", "Fifteen", "Thirty", "Forty"};

void score(char *score) {
    if (playerOnePoint == playerTwoPoint) {
        sprintf(score, "%s %s", scoreTexts[playerOnePoint], "All");
        return;
    }

    sprintf(score, "%s %s", scoreTexts[playerOnePoint], scoreTexts[playerTwoPoint]);
    return;
}

void playerOneScore() {
    playerOnePoint++;
}

void playerTwoScore() {
    playerTwoPoint++;
}

void reset() {
    playerOnePoint = 0;
    playerTwoPoint = 0;
}
