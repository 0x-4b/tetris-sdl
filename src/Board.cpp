#include "Board.h"

Board::Board(Pieces *pPieces, int pScreenHeight)
{
    mPieces = pPieces;
    mScreenHeight = pScreenHeight;
    InitBoard();
}

void Board::InitBoard()
{
    for (int i = 0; i < BOARD_WIDTH; ++i)
    {
        for (int j = 0; j < BOARD_HEIGHT; ++j)
        {
            mBoard[i][j] = POS_FREE;
        }
    }
}

void Board::StorePiece(int pX, int pY, int pPiece, int pRotation)
{
    for (int i1 = pX, i2 = 0; i2 < PIECE_BLOCKS; ++i1, ++i2)
    {
        for (int j1 = pY, j2 = 0; j2 < PIECE_BLOCKS; ++j1, ++j2)
        {
            if (mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0)
            {
                if (i1 >= 0 && i1 < BOARD_WIDTH && j1 >= 0 && j1 < BOARD_HEIGHT)
                    mBoard[i1][j1] = POS_FILLED;
            }
        }
    }
}

bool Board::IsGameOver()
{
    for (int i = 0; i < BOARD_WIDTH; ++i)
    {
        if (mBoard[i][0] == POS_FILLED)
            return true;
    }
    return false;
}

void Board::DeleteLine(int pY)
{
    for (int j = pY; j > 0; --j)
    {
        for (int i = 0; i < BOARD_WIDTH; ++i)
        {
            mBoard[i][j] = mBoard[i][j - 1];
        }
    }
}

void Board::DeletePossibleLines()
{
    for (int j = 0; j < BOARD_HEIGHT; ++j)
    {
        int i = 0;
        while (i < BOARD_WIDTH)
        {
            if (mBoard[i][j] != POS_FILLED)
                break;
            i++;
        }

        if (i == BOARD_WIDTH)
        {
            DeleteLine(j);
        }
    }
}

bool Board::IsFreeBlock(int pX, int pY)
{
    return mBoard[pX][pY] == POS_FREE;
}

int Board::GetXPosInPixels(int pPos)
{
    return ((BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) + (pPos * BLOCK_SIZE));
}

int Board::GetYPosInPixels(int pPos)
{
    return ((mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pPos * BLOCK_SIZE));
}

bool Board::IsPossibleMovement(int pX, int pY, int pPiece, int pRotation)
{
    for (int i1 = pX, i2 = 0; i2 < PIECE_BLOCKS; ++i1, ++i2)
    {
        for (int j1 = pY, j2 = 0; j2 < PIECE_BLOCKS; ++j1, ++j2)
        {
            if (mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0)
            {
                // Out of bounds
                if (i1 < 0 || i1 >= BOARD_WIDTH || j1 >= BOARD_HEIGHT)
                    return false;
                // Collides with existing block
                if (j1 >= 0 && !IsFreeBlock(i1, j1))
                    return false;
            }
        }
    }
    return true;
}

void Board::Reset()
{
    for (int i = 0; i < BOARD_WIDTH; ++i)
        for (int j = 0; j < BOARD_HEIGHT; ++j)
            mBoard[i][j] = POS_FREE;
}

int Board::GetBlockType(int x, int y) const
{
    return mBoard[x][y];
}