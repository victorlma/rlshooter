#include "defines.h"
#include "raylib.h"
#include "stdio.h"
void DEBUG_Log(int lv, const char *string, ...)
{
    va_list args;
    va_start(args, string);
    vprintf(string, args);
    va_end(args);
}

#include "game.h"
#include "interface.h"
#include "interface.c"

Interface interface = {0};


void ProcessInput()
{
    int a = GetKeyPressed();
    if_HandleKey(a);
}

void SetDefaultControls(void)
{
    if_SetKey(&interface.gamekeys.up, KEY_UP);
    if_SetKey(&interface.gamekeys.down, KEY_DOWN);
    if_SetKey(&interface.gamekeys.left, KEY_LEFT);
    if_SetKey(&interface.gamekeys.right, KEY_RIGHT);

    if_SetKey(&interface.gamekeys.b1, KEY_Z);
    if_SetKey(&interface.gamekeys.b2, KEY_X);
}

int main(void)
{

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetTraceLogCallback(DEBUG_Log);


    InitWindow(800, 600, "Shooter");

    SetTargetFPS(60);

    SetDefaultControls();


    while (!WindowShouldClose()) {
        ProcessInput();
        BeginDrawing();
        EndDrawing();
    }

    CloseWindow();


    return 0;
}
