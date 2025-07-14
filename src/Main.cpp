#include "Game.h"

IO mIO (BOARD_WIDTH, BOARD_HEIGHT);
int mScreenHeight = mIO.GetScreenHeight();

Pieces mPieces;

Board mBoard(&mPieces, mScreenHeight);
Game mGame(&mBoard, &mPieces, &mIO, mScreenHeight);

Uint32 mTime1 = SDL_GetTicks();

int main(int argc, char* argv[])
{
    while (!mIO.isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        mIO.ClearScreen();
        mGame.DrawScene();
        mIO.Present();
        SDL_Event e;
        int mKey = mIO.PollEvent(e);
        switch (mKey)
        {
        case SDLK_RIGHT:
            if (mBoard.IsPossibleMovement(mGame.mPosX + 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
                mGame.mPosX++;
            break;

        case SDLK_LEFT:
            if (mBoard.IsPossibleMovement(mGame.mPosX - 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
                mGame.mPosX--;
            break;

        case SDLK_DOWN:
            if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
                mGame.mPosY++;
            break;

        case SDLK_x:
            while (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
            {
                mGame.mPosY++;
            }

            mBoard.StorePiece(mGame.mPosX, mGame.mPosY - 1, mGame.mPiece, mGame.mRotation);
            mBoard.DeletePossibleLines();

            if (mBoard.IsGameOver())
            {
                SDL_Delay(3000);
                exit(0);
            }
            mGame.CreateNewPiece();
            break;

        case SDLK_z:

            if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, (mGame.mRotation + 1) % 4))
            {
                mGame.mRotation = (mGame.mRotation + 1) % 4;
            }
        }

        Uint32 mTime2 = SDL_GetTicks();
        if ((mTime2 - mTime1) > WAIT_TIME)
        {
            if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
                mGame.mPosY++;

            else
            {
                mBoard.StorePiece(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation);
                mBoard.DeletePossibleLines();

                if (mBoard.IsGameOver())
                    SDL_Delay(3000);
                exit(0);

                mGame.CreateNewPiece();
            }

            mTime1 = SDL_GetTicks();
        }
    }
    return 0;
}