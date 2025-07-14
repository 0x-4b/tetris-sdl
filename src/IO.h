#ifndef _IO_
#define _IO_

#include <SDL2/SDL.h>

enum color {BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX};

class IO {
    public :
        void DrawRectangle(int pX1, int pY1, int pX2, int pY2, enum color pC);
        void ClearScreen();
        int GetScreenHeight();
        int InitGraph();
        int PollKey();
        int GetKey();
        int isKeyDown (int pKey);
        void UpdateScreen();
};

#endif // _IO_