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
    
    //Wait for a button to be pressed
    //Start drawing
    
   
    while (isRunning()) {
       oslStartDrawing();
       oslClearScreen(RGB(70,130,180));
       oslMoveTo(0,0);
        oslReadKeys();
        oslDrawFillRect(5, getPlayerPos(),25 , getPlayerPos()+50, RGB(255, 0, 0));
        oslDrawFillRect(400, getCpuPos(),425 , getCpuPos()+50, RGB(255, 0, 255));
        oslDrawStringf(200,25,"Score: %d",getScore());
        if(osl_pad.pressed.up){
            movePlayerUp();
             //Draw player position
        }
        if(osl_pad.pressed.down){
            movePlayerDown();
        }
         oslEndDrawing();
         oslEndFrame();
         oslSyncFrame();

       // oslPrintf("%d", getScore()); // Should display the score somewhere
    }
   
    
    //terminate the program
    oslEndGfx();
    oslQuit();
    return 0;
}