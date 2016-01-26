/*
 * RestrictedPiece.cpp
 *
 * A class to represent a restricted piece in a game of chess
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#include "RestrictedPiece.h"
#include "Piece.h"

// Default constructor
RestrictedPiece::RestrictedPiece()
{
}

/*
 * Creates a RestrictedPiece at the given inital square 
 * with the given color
 *
 * @param initialSquare the square the piece starts out on
 * @param color the color of the piece
 */
RestrictedPiece::RestrictedPiece(string& color) :
Piece(color), _moved(false)
{
}

// Destructor
RestrictedPiece::~RestrictedPiece()
{
}

/*
 * Method to move a piece to a space
 *
 * @param byPlayer the player who moves the piece
 * @param to the square to move the piece to
 *
 * @return true if the move is successful
 */
const bool RestrictedPiece::moveTo(Player& byPlayer, Square& to)
{
    bool moveSuccess = false;
    if (Piece::moveTo(byPlayer, to))
    {
        // check to see if this has moved
        _moved = true;
        moveSuccess = true;
    }
    return moveSuccess;
}

/*
 * Method to see if the piece was moved
 *
 * @return true if the piece was moved
 */
const bool RestrictedPiece::hasMoved() const
{
    return _moved;
}