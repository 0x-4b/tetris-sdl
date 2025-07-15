#include "Font.h"

Font::Font() : mFont(nullptr), mTexture(nullptr), mWidth(0), mHeight(0) {}

Font::~Font()
{
    if (mTexture) SDL_DestroyTexture(mTexture);
    if (mFont) TTF_CloseFont(mFont);
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

bool Font::LoadFont(const std::string& path, int size)
{
    mFont = TTF_OpenFont(path.c_str(), size);
    if (!mFont)
    {
        std::cout << "Could not open font. TTF_Error: " << TTF_GetError() << '\n';
        return false;
    }
    return true;
}

bool Font::RenderText(const std::string& text, SDL_Color color, SDL_Renderer* renderer)
{
    if (mTexture) SDL_DestroyTexture(mTexture);
    SDL_Surface* textSurface = TTF_RenderText_Solid(mFont, text.c_str(), color);
    if (!textSurface)
    {
        std::cout << "Could not render text surface. TTF_Error: " << TTF_GetError() << '\n';
        return false;
    }
    mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (!mTexture)
    {
        std::cout << "Could not create texture. SDL_Error: " << SDL_GetError() << '\n';
        SDL_FreeSurface(textSurface);
        return false;
    }
    mWidth = textSurface->w;
    mHeight = textSurface->h;
    SDL_FreeSurface(textSurface);
    return true;
}

void Font::render(int pX, int pY, SDL_Rect *pClip, SDL_Renderer *pRenderer)
{
    SDL_Rect renderQuad = {pX, pY, mWidth, mHeight};

    if (pClip != nullptr)
    {
        renderQuad.w = pClip->w;
        renderQuad.h = pClip->h;
    }

    SDL_RenderCopy(pRenderer, mTexture, pClip, &renderQuad);
}

int Font::GetWidth()
{
    return mWidth;
}
int Font::GetHeight()
{
    return mHeight;
}