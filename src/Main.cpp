#include "Game.h"

int main(int argc, char* argv[])
{
    IO mIO(800, 600); // Use a large enough window
    if (!mIO.Init()) {
        return 1;
    }
    int mScreenHeight = mIO.GetScreenHeight();

    Pieces mPieces;
    Board mBoard(&mPieces, mScreenHeight);
    Game mGame(&mBoard, &mPieces, &mIO, mScreenHeight);

    Uint32 mTime1 = SDL_GetTicks();

    while (!mIO.isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        mIO.ClearScreen();
        mGame.DrawScene();
        mIO.Present();

        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) return 0;
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym)
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
                        mGame.mPosY++;
                    mBoard.StorePiece(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation);
                    mBoard.DeletePossibleLines();
                    if (mBoard.IsGameOver()) {
                        SDL_Delay(3000);
                        return 0;
                    }
                    mGame.CreateNewPiece();
                    break;
                case SDLK_z:
                    if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, (mGame.mRotation + 1) % 4))
                        mGame.mRotation = (mGame.mRotation + 1) % 4;
                    break;
                case SDLK_ESCAPE:
                    return 0;
                }
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
                if (mBoard.IsGameOver()) {
                    SDL_Delay(3000);
                    return 0;
                }
                mGame.CreateNewPiece();
            }
            mTime1 = SDL_GetTicks();
        }
    }
    return 0;
}