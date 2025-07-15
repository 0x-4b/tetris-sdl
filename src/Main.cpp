#include "Game.h"
#include "Font.h"

enum GameState
{
    MAIN_MENU,
    PLAYING,
    GAME_OVER,
    QUIT
};
GameState state = MAIN_MENU;

void ShowMainMenu(IO &io, Font &font, GameState &state);
void RunGame(IO &io, Board &board, Game &game, GameState &state);
void ShowGameOver(IO &io, Font &font, GameState &state);

int main(int argc, char *argv[])
{
    IO mIO(BOARD_POSITION * 2, 600);
    if (!mIO.Init())
    {
        return 1;
    }
    int mScreenHeight = mIO.GetScreenHeight();

    Pieces mPieces;
    Board mBoard(&mPieces, mScreenHeight);
    Game mGame(&mBoard, &mPieces, &mIO, mScreenHeight);
    Font mFont;
    if (!mFont.init())
    {
        return 1;
    }
    if (!mFont.LoadFont("./data/font.ttf", 40))
    {
        return 1;
    }

    GameState state = MAIN_MENU;

    while (state != QUIT)
    {
        switch (state)
        {
        case MAIN_MENU:
            ShowMainMenu(mIO, mFont, state);
            break;
        case PLAYING:
            mBoard.Reset();
            mGame.Reset();
            RunGame(mIO, mBoard, mGame, state);
            break;
        case GAME_OVER:
            ShowGameOver(mIO, mFont, state);
            break;
        default:
            break;
        }
    }

    return 0;
}

void ShowMainMenu(IO &io, Font &font, GameState &state)
{
    bool waiting = true;
    SDL_Event e;
    while (waiting)
    {
        io.ClearScreen();
        font.RenderText("TETRIS", {255, 255, 255, 255}, io.GetRenderer());
        font.render(BOARD_WIDTH / 2, 100, nullptr, io.GetRenderer());
        font.RenderText("Press any key to start", {255, 255, 255, 255}, io.GetRenderer());
        font.render(BOARD_WIDTH / 2, 200, nullptr, io.GetRenderer());
        io.Present();

        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_KEYDOWN || e.type == SDL_QUIT)
            {
                state = PLAYING;
                waiting = false;
            }
        }
    }
}

void RunGame(IO &io, Board &board, Game &game, GameState &state)
{
    Uint32 mTime1 = SDL_GetTicks();
    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        io.ClearScreen();
        game.DrawScene();
        io.Present();

        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
                state = GAME_OVER;
            }
            if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    if (board.IsPossibleMovement(game.mPosX + 1, game.mPosY, game.mPiece, game.mRotation))
                        game.mPosX++;
                    break;
                case SDLK_LEFT:
                    if (board.IsPossibleMovement(game.mPosX - 1, game.mPosY, game.mPiece, game.mRotation))
                        game.mPosX--;
                    break;
                case SDLK_DOWN:
                    if (board.IsPossibleMovement(game.mPosX, game.mPosY + 1, game.mPiece, game.mRotation))
                        game.mPosY++;
                    break;
                case SDLK_x:
                    while (board.IsPossibleMovement(game.mPosX, game.mPosY + 1, game.mPiece, game.mRotation))
                        game.mPosY++;
                    board.StorePiece(game.mPosX, game.mPosY, game.mPiece, game.mRotation);
                    board.DeletePossibleLines();
                    if (board.IsGameOver())
                    {
                        state = GAME_OVER;
                        return;
                    }
                    game.CreateNewPiece();
                    break;
                case SDLK_z:
                    if (board.IsPossibleMovement(game.mPosX, game.mPosY, game.mPiece, (game.mRotation + 1) % 4))
                        game.mRotation = (game.mRotation + 1) % 4;
                    break;
                case SDLK_ESCAPE:
                    quit = true;
                    state = MAIN_MENU;
                    return;
                }
            }
        }

        Uint32 mTime2 = SDL_GetTicks();
        if ((mTime2 - mTime1) > WAIT_TIME)
        {
            if (board.IsPossibleMovement(game.mPosX, game.mPosY + 1, game.mPiece, game.mRotation))
                game.mPosY++;
            else
            {
                board.StorePiece(game.mPosX, game.mPosY, game.mPiece, game.mRotation);
                board.DeletePossibleLines();
                if (board.IsGameOver())
                {
                    state = GAME_OVER;
                    return;
                }
                game.CreateNewPiece();
            }
            mTime1 = SDL_GetTicks();
        }
    }
}

void ShowGameOver(IO &io, Font &font, GameState &state)
{
    while (true)
    {
        io.ClearScreen();
        font.RenderText("GAME OVER", {255, 0, 0, 255}, io.GetRenderer());
        font.render((800 - font.GetWidth()) / 2, 100, nullptr, io.GetRenderer());
        font.RenderText("Press any key for menu", {255, 255, 255, 255}, io.GetRenderer());
        font.render((800 - font.GetWidth()) / 2, 200, nullptr, io.GetRenderer());
        io.Present();

        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_KEYDOWN)
            {
                state = MAIN_MENU;
                return;
            }
            if (e.type == SDL_QUIT)
            {
                state = QUIT;
                return;
            }
        }
    }
}
