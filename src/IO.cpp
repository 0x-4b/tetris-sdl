#include "IO.h"

IO::IO(int pWidth, int pHeight)
{
    mWidth = pWidth;
    mHeight = pHeight;

    mWindow = nullptr;
    mRenderer = nullptr;
}

IO::~IO()
{
    SDL_DestroyWindow(mWindow);
    mWindow = nullptr;

    SDL_DestroyRenderer(mRenderer);
    mRenderer = nullptr;

    SDL_Quit();
}
bool IO::Init()
{
}
void IO::ClearScreen() {}

void IO::DrawRectangle(int pX1, int pY1, int pX2, int pY2, SDL_Color pC)
{
}
void IO::Present() {}
int IO::PollEvent(SDL_Event &e) {}
int IO::isKeyDown(SDL_Scancode pKey) {}
int IO::GetScreenHeight() const
{
}