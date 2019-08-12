#ifndef PONG_H
#define PONG_H

#endif
int getPlayerScore();
int getCpuScore();

extern const int PLAYER_START_X;
extern const int  CPU_START_X;
extern const int PLAYER_END_X;
extern const int CPU_END_X;
extern const int PADDLE_WIDTH;
extern const int PADDLE_HEIGHT;

int getPlayerPos();
int movePlayerUp();
int movePlayerDown();

int getCpuPos();
int handleCpu();

int handleBall();