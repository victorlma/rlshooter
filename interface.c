#include "interface.h"
int if_HandleKey(int keycode)
{
    return 0;
}
int if_SetKey(u32 *gamekey, u32 keycode)
{
    b32 ret = 0;
    *gamekey = keycode;
    if (*gamekey) ret = TRUE;
    if (!*gamekey) ret = FALSE;

    return ret;
}


