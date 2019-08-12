#include "../common/ui.h"
#include "pong.h"

/**** Variables *****/



int player_score = 0;           // player score, should play until 10
int cpu_score = 0;
int player_pos = 0;      // Player  y position 
int cpu_pos = 0;                // Computer  y position
int move_speed = 3;             // Move speed for both the CPU and player

int ball_x_pos = 0;             // The ball x pos on screen
int ball_y_pos = 300;             // Ball y pos 
int ball_speed = 1;        // Ball velocity (should get faster more volley)

int game_over = 0; // if 1 game is over
//Constants
 const int PLAYER_START_X = 30;
 const int  CPU_START_X = 400;
 const int PLAYER_END_X = 5;
 const int CPU_END_X = 425;
 const int PADDLE_WIDTH = 25;
 const int PADDLE_HEIGHT = 50;
 const int WIN_SCORE = 10;
/*
    Returns the current score in the game
 */
 int getPlayerScore()
 {
     return player_score;
 }
 int getCpuScore(){
     return cpu_score;
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


/**
 * Handle the paddle AI
 * Jist of things is that it should try to hit the ball with the center of the paddle
 * More advanced could try calculating where to best hit the ball to where the player couldn't catch up..
 * 
 */
int handleCpu(){

    //if ball is coming towards
    if(ball_speed > 0){
        if(ball_y_pos < cpu_pos +(PADDLE_HEIGHT/2)){
            moveCpuUp();
            }
        else if(ball_y_pos > cpu_pos+(PADDLE_HEIGHT/2)){
            moveCpuDown();
        }
    }
    return 0;
}

/*
    Move the CPU up if able
 */

 int moveCpuUp(){
     if( cpu_pos - move_speed <= 0){ // don't move paddle above screen
         cpu_pos = 0;
          return 0;
     } 
     else{
         cpu_pos = cpu_pos - move_speed;
         return 0;
     }
 }
/*
    Moves the player down if able
 */
int moveCpuDown(){
     if(cpu_pos+PADDLE_HEIGHT + move_speed >= (272)){ // Don't move paddle below screen
        cpu_pos = 272 - PADDLE_HEIGHT;
        return 0;
     }
     else{
         cpu_pos = cpu_pos + move_speed;
         return 0;
     }
 }

/**
 * Handle the movement of the ball and incrementing score
 * 
 */

int handleBall(){
    ball_y_pos = player_pos;
    //Handle hiting player paddle

    //Handle hitting cpu paddle

    //handle going past player

    //handle going past cpu

    //handle hitting top of screen

    //handle hitting bottom of screen
    return 0;
}




