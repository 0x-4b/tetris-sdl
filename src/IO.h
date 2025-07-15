#ifndef _IO_
#define _IO_

#include <SDL2/SDL.h>
#include <iostream>
class IO
{
public:
    IO(int pWidth, int pHeight);
    ~IO();
    void ClearScreen();
    void DrawRectangle(int pX1, int pY1, int pX2, int pY2, SDL_Color pC);
    bool Init();
    void Present();
    int GetScreenHeight() const;
    SDL_Renderer* GetRenderer() const;

private:
    SDL_Window *mWindow;
    SDL_Renderer *mRenderer;
    int mWidth, mHeight;
};

#endif // _IO_