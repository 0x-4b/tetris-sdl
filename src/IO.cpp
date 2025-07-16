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

void IO::ClearScreen()
{
    SDL_SetRenderDrawColor(mRenderer, 0x26, 0x26, 0x26, 0xff);
    SDL_RenderClear(mRenderer);
}

void IO::DrawRectangle(int pX1, int pY1, int pX2, int pY2, SDL_Color pC)
{
    SDL_SetRenderDrawColor(mRenderer, pC.r, pC.g, pC.b, pC.a);

    int x = std::min(pX1, pX2);
    int y = std::min(pY1, pY2);
    int width = abs(pX2 - pX1) + 1;
    int height = abs(pY2 - pY1) + 1;

    SDL_Rect rect = {x, y, width, height};

    SDL_RenderFillRect(mRenderer, &rect);
}
void IO::DrawRectangleOutline(int pX1, int pY1, int pX2, int pY2, SDL_Color pC)
{
    SDL_SetRenderDrawColor(mRenderer, pC.r, pC.g, pC.b, pC.a);

    int x = std::min(pX1, pX2);
    int y = std::min(pY1, pY2);
    int width = abs(pX2 - pX1) + 1;
    int height = abs(pY2 - pY1) + 1;

    SDL_Rect rect = {x, y, width, height};

    SDL_RenderDrawRect(mRenderer, &rect);
}

void IO::Present()
{
    SDL_RenderPresent(mRenderer);
}

int IO::GetScreenHeight() const
{
    return mHeight;
}

SDL_Renderer *IO::GetRenderer() const
{
    return mRenderer;
}