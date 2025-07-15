#ifndef _FONT_
#define _FONT_

#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>

class Font
{
public:
    Font();
    ~Font();
    bool init();
    bool LoadFromRenderedText(TTF_Font *pFont, std::string pText, SDL_Color pColor, SDL_Renderer *pRenderer);
    bool LoadMedia(std::string pText);

    void render(int pX, int pY, SDL_Rect *pClip, SDL_Renderer *pRenderer);

    int GetWidht();
    int GetHeight();

private:
    SDL_Texture *mTexture;
    int mWidth, mHeight;
};
#endif // _FONT_