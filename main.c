#include <stdio.h>
#include <termios.h> 
#include <fcntl.h>
#include <unistd.h> 


#define MAX_SCORE 10



typedef struct {
	float x; // will be fixed for each paddle 
	float y; // we will change this value
		 
} Paddle;

typedef struct {
	float x;
	float y; 

	float xVelo;
	float yVelo;
} Ball; 


// holds the game state
typedef struct {
	Paddle leftPaddle; 
	Paddle rightPaddle;

	int leftScore;
	int rightScore;

	Ball ball;


} GameState;


void ConfigTerminal();

int main()
{

	GameState gs ;
	

	

	SetNonCanonical();

	while(gs.leftScore < MAX_SCORE || gs.rightScore < MAX_SCORE)
	{
		// Read Input
		ProcessInput(&gs);


		
		// Update Game State
		
		// Draw
		
		// Sleep/Wait for refresh

	}





	SetCanonical();
	return 0;
}


//Game loop functions

void ProcessInput(struct GameState * gs)
{
	char input;

	read(STDIN_FILENO, &input, 1);



}





// Terminal utility functions




// Configure the terminal to be able to run 
// how we want for a game. 
void SetUpTerminal()
{
	struct termios newConfig;

	//0 is standard input
	tcgetattr(STDIN_FILENO, &newConfig);

	// turn off canonical mode in the terminal
	// ~ flips icanon opposite and the bitwise and turns on that
	// bit in the c_lflag bitstring
	new_config.c_lflag &= ~(ICANON);
	new_config.c_lflag &= ~(ECHO);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &new_config);


	// use fnctl to make read() non blocking




}


// Reset the terminal to original settings
void ResetTerminal()
{
	struct termios newConfig;

	tcgetatter(STDIN_FILENO, &newConfig);

	// Reset cononical mode and echo
	// for original term settings
	newConfig.c_lflag &= ICANON;
	newConfig.c_lflag &= ECHO;
	tcsetattr(STDIN_FILENO, &newConfig);
}

