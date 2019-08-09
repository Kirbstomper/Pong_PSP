// include psp stuff
#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>
 
// include commons stuff
#include "common/callback.h"
#include "common/ui.h"
#include "game/pong.h"
 
 
// configure PSP stuff
#define VERS    1
#define REVS    0
 
PSP_MODULE_INFO("Pong", PSP_MODULE_USER, VERS, REVS);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
 
// make printing easier on us
#define printf pspDebugScreenPrintf
 
int main(int argc, char** argv)
{
    // basic init
    setupExitCallback();
    pspDebugScreenInit();
   
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);
   
    while (isRunning()) {
        sceDisplayWaitVblankStart();
        pspDebugScreenClear();
        pspDebugScreenSetXY(0, 0);
        pollPad();
        pollLatch();
        
        if(isKeyHold(PSP_CTRL_UP)){
            movePlayerUp();
            printf("%d",getPlayerPos()); // Should send to game to move player position up
        }
        if(isKeyHold(PSP_CTRL_DOWN)){
            movePlayerDown();
            printf("%d",getPlayerPos()); // Should send to game to move player position up
        }
            

        printf("%d", getScore()); // Should display the score somewhere
    }
   
    sceKernelExitGame();
    return 0;
}