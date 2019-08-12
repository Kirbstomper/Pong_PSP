#include "../common/ui.h"
#include "pong.h"

/**** Variables *****/

static int score = 0;           // Score, should play until 10
static int player_pos = 0;      // Player y position 
int cpu_pos = 0;                // Computer y position
int move_speed = 3;             // Move speed for both the CPU and player

int ball_x_pos = 0;             // The ball x pos
int ball_y_pos = 0;             // Ball y pos
float ball_speed = 0.0f;        // Ball velocity (should get faster more volley)

//Constants
 const int PLAYER_START_X = 30;
 const int  CPU_START_X = 400;
 const int PLAYER_END_X = 5;
 const int CPU_END_X = 425;
 const int PADDLE_WIDTH = 25;
 const int PADDLE_HEIGHT = 50;

/*
    Returns the current score in the game
 */
 int getScore()
 {
     return score;
 }

/*
    Return the current player position
 */
int getPlayerPos(){
    return player_pos;
}

int getCpuPos(){
    return cpu_pos; 
}
/*
    Move the player up if able
 */

 int movePlayerUp(){
     if(player_pos - move_speed <= 0){ // don't move paddle above screen
         player_pos = 0;
          return 0;
     } 
     else{
         player_pos = player_pos - move_speed;
         return 0;
     }
 }
/*
    Moves the player down if able
 */
int movePlayerDown(){
     if(player_pos+PADDLE_HEIGHT + move_speed >= (272)){ // Don't move paddle below screen
        player_pos = 272 - PADDLE_HEIGHT;
        return 0;
     }
     else{
         player_pos = player_pos + move_speed;
         return 0;
     }
 }
