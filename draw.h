#ifndef DRAW_H
#define DRAW_H

#include "components.h"

void drawBorders();

void drawBoard(GameState, FILE*);

void drawPaddle(float, float, FILE*);

void drawBall(float, float);

#endif





