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
                SDL_Color fillColor = pieceColors[pPiece];
                SDL_Color outlineColor = {0, 0, 0, 255}; // black outline

                int x1 = mPixelsX + i * BLOCK_SIZE;
                int y1 = mPixelsY + j * BLOCK_SIZE;
                int x2 = x1 + BLOCK_SIZE - 1;
                int y2 = y1 + BLOCK_SIZE - 1;

                // Draw filled block
                mIO->DrawRectangle(x1, y1, x2, y2, fillColor);

                // Draw outline
                mIO->DrawRectangleOutline(x1, y1, x2, y2, outlineColor);
            }
        }
    }
}

void Game::DrawBoard()
{
    int mX1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
    int mX2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
    int mY = mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT);

    mIO->DrawRectangle(mX1 - BOARD_LINE_WIDTH, mY, mX1, mScreenHeight - 1, {0, 0, 0, 255});
    mIO->DrawRectangle(mX2, mY, mX2 + BOARD_LINE_WIDTH, mScreenHeight - 1, {0, 0, 0, 255});

    mX1 += 1;

    for (int i = 0; i < BOARD_WIDTH; ++i)
    {
        for (int j = 0; j < BOARD_HEIGHT; ++j)
        {
            int blockType = mBoard->GetBlockType(i, j); 

            if (blockType != 0) 
            {
                SDL_Color blockColor = pieceColors[blockType - 1]; 

                int x1 = mX1 + i * BLOCK_SIZE;
                int y1 = mY + j * BLOCK_SIZE;
                int x2 = x1 + BLOCK_SIZE - 1;
                int y2 = y1 + BLOCK_SIZE - 1;

                // Draw filled block with color
                mIO->DrawRectangle(x1, y1, x2, y2, blockColor);

                // Draw black outline around block
                mIO->DrawRectangleOutline(x1, y1, x2, y2, {0, 0, 0, 255});
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