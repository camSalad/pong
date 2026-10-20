#include <stdio.h> 
#include "draw.h"

#define POS "\033[%d;%dH%c"


void clearScreen()
{
  printf("\033[2J");
}

// big objective is to see why the drawing seems to be moving so
// slow even moving from one position to another is going super
// slow. I know its not the sleep because the cursor is moving
// while moving from one position to another.
//
//
//
// do i need to change my approach on how I am drawing
// should I render / generate the game scene in an array and
// then draw the game scene
void drawBoard(GameState gs, FILE * logFile)
{

	// clear screen and move to home position (top left)
	printf("\033[H");

	// quick null check
	//if(gs == NULL) {return;} 

	//drawPaddle(gs.leftPaddle.x, gs.leftPaddle.y);
  drawPaddle(gs.leftPaddle.x, gs.leftPaddle.y, logFile );


   //drawBall(gs.ball.x, gs.ball.y);
   //drawBorders(); 
}


void drawBorders()
{
	// top and bottom borders
	for(int x = 1; x < 120; x++)
	{
		printf(POS, 1, x, '_');
		//printf("%c", '_');
		printf(POS, 60, x, '_');
		//printf("%c", '_');
		
	}

	// side to side 
	for(int y = 1; y < 60; y++)
	{
		printf(POS, y, 1, '|');
		//printf("%c", '|');
		printf(POS, y, 120, '|');
		//printf("%c", '|');
	}
	


}


void drawBall(float x, float y)
{
	// This will need to be hardened up on the upper and lower positions

}


// why is it so slow
void drawPaddle(int a, int v, FILE * logFile)
{

	int x = 10, y = 10; 
 
	//move position to center of where paddle is 
	printf(POS, a, v, '|'); 
//  fprintf(logFile, "Printing | @ x: %d, y: %d\n", x, y);
//	printf("|");

	// above center
  printf(POS, a + 1, v, '|'); 
 // fprintf(logFile, "Printing | @ x: %d, y: %d\n", x, y);
//	printf("|");

	
  printf(POS, a - 1, v, '|'); 
  //fprintf(logFile, "Printing | @ x: %d, y: %d\n", x, y);
//	printf("|");
}






