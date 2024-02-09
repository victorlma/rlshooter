#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "defines.h"
#include "game.h"

typedef struct GameKeys 
{
    u32     up;
    u32     down;
    u32     left;
    u32     right;

    u32     b1;
    u32     b2;

} GameKeys;

typedef struct Scene
{
    void (*process)();
    void (*update)();
} Scene;

typedef struct Interface
{
    GameKeys     gamekeys;
    Scene        scene;
} Interface;


int if_HandleKey(int  keycode);
int if_SetKey(u32 *gamekey, u32 keycode);

#endif
