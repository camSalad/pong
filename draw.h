#ifndef DRAW_H
#define DRAW_H

#include "components.h"

void clearScreen();

void drawBorders();

void drawBoard(GameState, FILE*);

void drawPaddle(int, int, FILE*);

void drawBall(float, float);

#endif





