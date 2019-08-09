#ifndef UI_H
#define UI_H

#endif

int getJX();
int getJY();

void pollPad();
void pollLatch();

int isKeyHold(int key); // Return 1(true) if keyt is down

int isKeyDown(int key);
int isKeyUp(int key);