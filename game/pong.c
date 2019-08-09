#include "../common/ui.h"
#include "pong.h"

/**** Variables *****/

static int score = 0;           // Score, should play until 10
static int player_pos = 0;      // Player y position 
int cpu_pos = 0;                // Computer y position
int move_speed = 1;             // Move speed for both the CPU and player

int ball_x_pos = 0;             // The ball x pos
int ball_y_pos = 0;             // Ball y pos
float ball_speed = 0.0f;        // Ball velocity (should get faster more volley)


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


/*
    Move the player up if able
 */

 int movePlayerUp(){
     if(player_pos == 0)
        return 0;
     else{
         player_pos = player_pos - 1;
         return 0;
     }
 }
/*
    Moves the player down if able
 */
int movePlayerDown(){
     if(player_pos == (100-1))
        return 0;
     else{
         player_pos = player_pos + 1;
         return 0;
     }
 }
