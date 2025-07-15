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
    bool LoadFont(const std::string& path, int size);
    bool RenderText(const std::string& text, SDL_Color color, SDL_Renderer* renderer);

    void render(int x, int y, SDL_Rect* clip, SDL_Renderer* renderer);

    int GetWidth();
    int GetHeight();

private:
    TTF_Font* mFont;
    SDL_Texture* mTexture;
    int mWidth, mHeight;
};

#endif // _FONT_