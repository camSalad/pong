#include <termios.h> 
#include <fcntl.h>
#include <unistd.h> 
#include <stdio.h>

#include "draw.h"
#include "components.h"

#define MAX_SCORE 10

void SetNonCanonical();
void SetCanonical();
void ProcessInput(GameState * gs);

int main(void)
{
	
	FILE * logFile = fopen("log.txt", O_RDWR);

	SetNonCanonical();
	// GameState contains
	// leftPaddle
	// rightPaddle
	// int leftScore
	// int rightScore
	// ball
	GameState gs = {
		.leftPaddle = { .x = 10.0, .y = 10.0},
		.rightPaddle = {.x = 50.0, .y = 10.0}, 
		.leftScore = 0, 
		.rightScore = 0,
		.ball = {.x = 25.0, .y = 25.0, .xVelo = 0.0, .yVelo = 0.0}
	};

	//drawBoard(gs);

  while(gs.leftScore < MAX_SCORE || gs.rightScore < MAX_SCORE)
	{
		// Read Input
		//ProcessInput(&gs);
		
		// Update Game State
		
		// Draw
		drawBoard(gs, logFile);
		
		// Sleep/Wait for refresh
		usleep(160);
	}

	//cleanup 
	SetCanonical();
	fclose(logFile);
	return 0;
}


//Game loop functions

//Process our input and update game state from there
void ProcessInput(GameState * gs)
{
	char input;

	read(STDIN_FILENO, &input, 1);
}


// Terminal utility functions

// Configure the terminal to be able to run 
// how we want for a game. 
void SetNonCanonical()
{
	struct termios newConfig;

	//0 is standard input
	tcgetattr(STDIN_FILENO, &newConfig);

	// turn off canonical mode in the terminal
	// ~ flips icanon opposite and the bitwise and turns on that
	// bit in the c_lflag bitstring
	newConfig.c_lflag &= ~(ICANON);
	newConfig.c_lflag &= ~(ECHO);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &newConfig);


	// need to set read to non blocking as well? 
	// should only read if there is something to read
	// not wait until there is something there. 
	int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

}


// Reset the terminal to original settings
void SetCanonical()
{
	struct termios newConfig;

	tcgetattr(STDIN_FILENO, &newConfig);

	// Reset cononical mode and echo
	// for original term settngs
	newConfig.c_lflag &= ICANON;
	newConfig.c_lflag &= ECHO;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &newConfig);

	// reset
	int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

}


