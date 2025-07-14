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

    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Could not initialize SDL. SDL_Error: " << SDL_GetError() << '\n';
        success = false;
    }
    else
    {
        mWindow = SDL_CreateWindow("Tetris SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mWidth, mHeight, SDL_WINDOW_SHOWN);

        if (mWindow == nullptr)
        {
            std::cout << "Could not create a window. SDL_Error: " << SDL_GetError() << '\n';

            success = false;
        }
        else
        {
            mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

            if (mRenderer == nullptr)
            {

                std::cout << "Could not create a renderer. SDL_Error: " << SDL_GetError() << '\n';

                success = false;
            }
        }
    }
    return success;
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