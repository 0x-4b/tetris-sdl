#ifndef _IO_
#define _IO_

#include <SDL2/SDL.h>

class IO
{
public:
    IO();
    ~IO();
    void ClearScreen();
    void DrawRectangle(int pX1, int pY1, int pX2, int pY2, SDL_Color pC);
    void Present();
    int PollEvent(SDL_Event &e);
    int isKeyDown(SDL_Scancode pKey);
    int GetScreenHeight() const;

private:
    SDL_Window *mWindow;
    SDL_Renderer *mRenderer;
    int mWidth, mHeight;
};

#endif // _IO_