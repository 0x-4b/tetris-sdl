#include "Pieces.h"

/*
[kind][rotation][horizontal][vertical]
*/
static const char gPieces[7][4][5][5] =
    {
        {
            // Square
            {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 2, 1, 0},
                {0, 0, 1, 1, 0},
                {0, 0, 0, 0, 0},
            },
            {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 2, 1, 0},
                {0, 0, 1, 1, 0},
                {0, 0, 0, 0, 0},
            },
            {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 2, 1, 0},
                {0, 0, 1, 1, 0},
                {0, 0, 0, 0, 0},
            },
            {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 2, 1, 0},
                {0, 0, 1, 1, 0},
                {0, 0, 0, 0, 0},
            },

        },
        {
            // |

            {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 1, 2, 1, 1},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
            },
            {
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 2, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 1, 0, 0},
            },
            {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {1, 1, 2, 1, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
            },
            {
                {0, 0, 1, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 2, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0},
            },
        },

        {
            // L

            {
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 2, 0, 0},
                {0, 0, 1, 1, 0},
                {0, 0, 0, 0, 0},
            },
            {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 1, 2, 1, 0},
                {0, 1, 0, 0, 0},
                {0, 0, 0, 0, 0},
            },
            {
                {0, 0, 0, 0, 0},
                {0, 1, 1, 0, 0},
                {0, 0, 2, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0},
            },
            {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 1, 0},
                {0, 1, 2, 1, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
            },
        },
        {
            // L mirrored

            {
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 2, 0, 0},
                {0, 1, 1, 0, 0},
                {0, 0, 0, 0, 0},
            },
            {
                {0, 0, 0, 0, 0},
                {0, 1, 0, 0, 0},
                {0, 1, 2, 1, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
            },
            {
                {0, 0, 0, 0, 0},
                {0, 0, 1, 1, 0},
                {0, 0, 2, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0},
            },
            {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 1, 2, 1, 0},
                {0, 0, 0, 1, 0},
                {0, 0, 0, 0, 0},
            },
        },
        {
            // N

            {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 1, 0},
                {0, 0, 2, 1, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0},
            },
            {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 1, 2, 0, 0},
                {0, 0, 1, 1, 0},
                {0, 0, 0, 0, 0},
            },
            {
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 1, 2, 0, 0},
                {0, 1, 0, 0, 0},
                {0, 0, 0, 0, 0},
            },
            {
                {0, 0, 0, 0, 0},
                {0, 1, 1, 0, 0},
                {0, 0, 2, 1, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
            },
        },

        {
            // N mirrored

            {
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 2, 1, 0},
                {0, 0, 0, 1, 0},
                {0, 0, 0, 0, 0},
            },
            {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 2, 1, 0},
                {0, 1, 1, 0, 0},
                {0, 0, 0, 0, 0},
            },
            {
                {0, 0, 0, 0, 0},
                {0, 1, 0, 0, 0},
                {0, 1, 2, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0},
            },
            {
                {0, 0, 0, 0, 0},
                {0, 0, 1, 1, 0},
                {0, 1, 2, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
            },
        },
        {
            // T

            {
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 2, 1, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0},
            },
            {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 1, 2, 1, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0},
            },
            {
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 1, 2, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0},
            },
            {
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 1, 2, 1, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
            },
        },
};

// Displacement to the position where first drawn
/*
[kind][rotation][position]
 */
static const int gPiecesInitialPosition[7][4][2] = {
    {
        // Square
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -3},
    },
    {
        // |
        {-2, -2},
        {-2, -3},
        {-2, -2},
        {-2, -3},
    },
    {
        // L
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2},
    },
    {
        // L mirrored
        {-2, -3},
        {-2, -2},
        {-2, -3},
        {-2, -3},
    },
    {
        // N
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2},
    },
    {
        // N mirrored
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2},
    },
    {
        // T
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2},
    },
};

/* --------------------------------------------------- */

int Pieces::GetBlockType(int pPiece, int pRotation, int pX, int pY)
{
    return gPieces[pPiece][pRotation][pX][pY];
}
int Pieces::GetXInitialPosition(int pPiece, int pRotation)
{
    return gPiecesInitialPosition[pPiece][pRotation][0];
}
int Pieces::GetYInitialPosition(int pPiece, int pRotation)
{

    return gPiecesInitialPosition[pPiece][pRotation][1];
}