#ifndef COMPONENTS_H
#define COMPONENTS_H

// Paddle info
typedef struct{
	// should these be ints
	float x;
	float y;

} Paddle;


// Ball info
typedef struct {
  float x;
	float y;

	float xVelo; 
	float yVelo; 

} Ball; 

//Game State
typedef struct {
	Paddle leftPaddle;
	Paddle rightPaddle; 

	int leftScore;
	int rightScore;

	Ball ball; 

} GameState;


#endif
