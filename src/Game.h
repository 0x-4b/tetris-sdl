#ifndef _GAME_
#define _GAME_

#include "Board.h"
#include "Pieces.h"
#include "IO.h"
#include <time.h>

#define WAIT_TIME 700
const SDL_Color GREEN = {0x00, 0xff, 0x00, 0xff};
const SDL_Color BLUE = {0x00, 0x00, 0xff, 0xff};
const SDL_Color RED = {0xff, 0x00, 0x00, 0xff};

class Game
{
public:
    Game(Board *pBoard, Pieces *pPiece, IO *pIO, int pScreenHeight);

    void DrawScene();
    void CreateNewPiece();

    int mPosX, mPosY;
    int mPiece, mRotation;

private:
    int mScreenHeight;
    int mNextPosX, mNextPosY;
    int mNextPiece, mNextRotation;

    Board *mBoard;
    Pieces *mPieces;
    IO *mIO;

    int GetRand(int pA, int pB);
    void InitGame();
    void DrawPiece(int pX, int pY, int pPiece, int pRotation);
    void DrawBoard();
};

#endif // _GAME_