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

bool Font::LoadMedia(std::string pText, std::string pPath, TTF_Font *pFont, int pFontSize, SDL_Color pColor, SDL_Renderer *pRenderer)
{

    bool success = true;

    pFont = TTF_OpenFont(pPath.c_str(), pFontSize);
    if (pFont == nullptr)
    {
        std::cout << "Could not open font. TTF_Error: " << TTF_GetError() << '\n';
        success = false;
    }

    else
    {
        if (!this->LoadFromRenderedText(pFont, pText.c_str(), pColor, pRenderer))
        {
            std::cout << "Failed to render text\n";
            success = false;
        }
    }
    return success;
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

int Font::GetWidht()
{
    return mWidth;
}
int Font::GetHeight()
{
    return mHeight;
}