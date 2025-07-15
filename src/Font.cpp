#include "Font.h"

Font::Font()
{
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
}

Font::~Font()
{
    SDL_DestroyTexture(mTexture);
    mTexture = nullptr;

    mWidth = 0;
    mHeight = 0;
    TTF_Quit();
}

bool Font::init()
{
    if (TTF_Init() == -1)
    {
        std::cout << "Could not load TTF. TTF_Error: " << TTF_GetError() << '\n';
        return false;
    }
    return true;
}

bool Font::LoadFromRenderedText(TTF_Font *pFont, std::string pText, SDL_Color pColor, SDL_Renderer *pRenderer)
{

    SDL_Surface *TextSurface = TTF_RenderText_Solid(pFont, pText.c_str(), pColor);
    if (TextSurface == nullptr)
    {
        std::cout << "Could not render text surface. TTF_Error: " << TTF_GetError() << '\n';
    }
    else
    {
        mTexture = SDL_CreateTextureFromSurface(pRenderer, TextSurface);
        if (mTexture = nullptr)
        {

            std::cout << "Could not create texture. SDL_Error: " << SDL_GetError() << '\n';
        }

        else
        {
            mWidth = TextSurface->w;
            mHeight = TextSurface->h;
        }

        SDL_FreeSurface(TextSurface);
    }

    return mTexture != nullptr;
}
bool Font::LoadMedia(std::string pText) {}

void Font::render(int pX, int pY, SDL_Rect *pClip, SDL_Renderer *pRenderer) {}

int Font::GetWidht() {}
int Font::GetHeight() {}