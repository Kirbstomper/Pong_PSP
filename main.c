// include psp stuff

#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include <pspgu.h>



#include<oslib/oslib.h>


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
// RGB to decimal color conversion macro

int main(int argc, char** argv)
{
    // basic init
    setupExitCallback();
    pspDebugScreenInit();

    //Writing to display
    sceDisplaySetMode(0,480,272);
    sceDisplaySetFrameBuf(0x4000000, 512, 3, 1);

    //Initialization of the Oslib library
    oslInit(0);

    //Initialization of the graphics mode
    oslInitGfx(OSL_PF_8888, 1);
    
    //Initialization of the text console
    oslInitConsole();

    //Print on the screen this text
    oslPrintf("Hello World");
    
   
    
   
    while (isRunning()) {
       oslStartDrawing();
       oslClearScreen(RGB(70,130,180));                                            // Clear screen to display background colour

        oslReadKeys();
        oslDrawFillRect(PLAYER_START_X, getPlayerPos(),PLAYER_END_X,getPlayerPos()+PADDLE_HEIGHT, RGB(255, 0, 0)); // Draw player position
        oslDrawFillRect(CPU_START_X, getCpuPos(),CPU_END_X, getCpuPos()+PADDLE_HEIGHT, RGB(255, 0, 255));  // Draw computer position
        oslDrawStringf(200,25,"Score: %d",getScore());                             // display score on screen
        
    
        /*** Handle player input ****/
        
        if(osl_pad.held.up){
            movePlayerUp();
        }
        if(osl_pad.held.down){
            movePlayerDown();
        }

        /****Handle the ball ******/

        //Finish drawing the frame
         oslEndDrawing();
         oslEndFrame();
         oslSyncFrame();

    }
   
    
    //terminate the program
    oslEndGfx();
    oslQuit();
    return 0;
}