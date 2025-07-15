#include "Font.h"

Font::Font()
{
    mWidth = 0;
    mHeight = 0;
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
bool Font::LoadFromRenderedText(std::string pText, SDL_Color pColor) {}
bool Font::LoadMedia(std::string pText) {}

void Font::render(int pX, int pY, SDL_Rect *pClip, SDL_Renderer *pRenderer) {}

int Font::GetWidht() {}
int Font::GetHeight() {}