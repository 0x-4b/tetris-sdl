#ifndef _GAME_
#define _GAME_

#include "Board.h"
#include "Pieces.h"
#include "IO.h"
#include <time.h>

#define WAIT_TIME 700

SDL_Color pieceColors[7] = {
    {0, 255, 255, 255}, // I (cyan)
    {255, 255, 0, 255}, // O (yellow)
    {128, 0, 128, 255}, // T (purple)
    {0, 255, 0, 255},   // S (green)
    {255, 0, 0, 255},   // Z (red)
    {0, 0, 255, 255},   // J (blue)
    {255, 165, 0, 255}  // L (orange)
};

class Game
{
public:
    Game(Board *pBoard, Pieces *pPiece, IO *pIO, int pScreenHeight);

    void DrawScene();
    void CreateNewPiece();
    void Reset();

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