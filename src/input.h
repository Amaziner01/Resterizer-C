#ifndef INPUT_H
#define INPUT_H

#include <windows.h>

#define get_keys() GetKeyboardState(_keys);

static unsigned char _keys[255];

bool key_pressed(unsigned char k)
{
    return (_keys[k] & 0x80);
}

POINT get_mouse(HWND wnd)
{
    POINT cursor;
    GetCursorPos(&cursor);
    ScreenToClient(wnd, &cursor);

    cursor.y = height - cursor.y;

    return cursor;
}

#endif
