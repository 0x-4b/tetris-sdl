#include "Game.h"

Game::Game(Board *pBoard, Pieces *pPiece, IO *pIO, int pScreenHeight)
{
    mBoard = pBoard;
    mPieces = pPiece;
    mIO = pIO;
    mScreenHeight = pScreenHeight;
    InitGame();
}

void Game::DrawScene()
{
    DrawBoard();
    DrawPiece(mPosX, mPosY, mPiece, mRotation);
    DrawPiece(mNextPosX, mNextPosY, mNextPiece, mNextRotation);
}

void Game::CreateNewPiece()
{
    mPiece = mNextPiece;
    mRotation = mNextRotation;
    mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition(mPiece, mRotation);
    mPosY = mPieces->GetYInitialPosition(mPiece, mRotation);

    mNextPiece = GetRand(0, 6);
    mNextRotation = GetRand(0, 3);
}

int Game::GetRand(int pA, int pB)
{
    return rand() % (pB - pA + 1) + pA;
}

void Game::InitGame()
{
    srand((unsigned int)time(NULL));

    mPiece = GetRand(0, 6);
    mRotation = GetRand(0, 3);

    mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition(mPiece, mRotation);
    mPosY = mPieces->GetYInitialPosition(mPiece, mRotation);

    mNextPiece = GetRand(0, 6);
    mNextRotation = GetRand(0, 3);
    mNextPosX = BOARD_WIDTH + 5;
    mNextPosY = 5;
}

void Game::DrawPiece(int pX, int pY, int pPiece, int pRotation)
{
    int mPixelsX = mBoard->GetXPosInPixels(pX);
    int mPixelsY = mBoard->GetYPosInPixels(pY);

    for (int i = 0; i < PIECE_BLOCKS; ++i)
    {
        for (int j = 0; j < PIECE_BLOCKS; ++j)
        {

            if (mPieces->GetBlockType(pPiece, pRotation, j, i) != 0)
            {   

                SDL_Color mColor = pieceColors[pPiece];

                mIO->DrawRectangle((mPixelsX + i * BLOCK_SIZE),
                                   (mPixelsY + j * BLOCK_SIZE),
                                   ((mPixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - 1),
                                   ((mPixelsY + j * BLOCK_SIZE) + BLOCK_SIZE - 1),
                                   mColor);
            }
        }
    }
}

void Game::DrawBoard()
{
    int mX1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
    int mX2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
    int mY = mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT);

    mIO->DrawRectangle(mX1 - BOARD_LINE_WIDTH, mY, mX1, mScreenHeight - 1, {0, 0, 0, 0});
    mIO->DrawRectangle(mX2, mY, mX2 + BOARD_LINE_WIDTH, mScreenHeight - 1, {0, 0, 0, 0});

    mX1 += 1;
    for (int i = 0; i < BOARD_WIDTH; ++i)
    {
        for (int j = 0; j < BOARD_HEIGHT; ++j)
        {
            if (!(mBoard->IsFreeBlock(i, j)))
            {
                mIO->DrawRectangle((mX1 + i * BLOCK_SIZE),
                                   (mY + j * BLOCK_SIZE),
                                   ((mX1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1),
                                   ((mY + j * BLOCK_SIZE) + BLOCK_SIZE - 1),
                                   {0, 0, 0, 0});
            }
        }
    }
}

void Game::Reset()
{
    mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition(0, 0);
    mPosY = mPieces->GetYInitialPosition(0, 0);
    mPiece = 0;
    mRotation = 0;
}