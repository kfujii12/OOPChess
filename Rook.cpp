/*
 * Rook.cpp
 *
 * A class to represent a rook in a game of chess
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#include "Rook.h"
#include "Square.h"
#include "Board.h"

// Default constructor
Rook::Rook()
{
}

/*
 * Creates a Rook at the given inital square with the given color
 *
 * @param initialSquare the square the piece starts out on
 * @param color the color of the piece
 */
Rook::Rook(string& color) :
RestrictedPiece(color)
{
}

// Destructor
Rook::~Rook()
{
}

/*
 * Method to see if the Rook can move to the specified space
 *
 * @param location the Square to attempt to move the Rook to
 */
const bool Rook::canMoveTo(Square& location) const
{
    bool legalMove = false;
    
    // If the square is not already occupied by another piece and
    // that piece is not of the same color
    if (!location.occupied() ||
        (location.occupiedBy().color() != this->color()))
    {
        // A rook can move horizontally or vertically in
        // any direction
        
        // if the square is in a horizontal line from the original location
        // and the diagonal path is clear then the move is legal
        if (this->location().getX() == location.getX())
        {
            if (Board::getBoard().
                isClearHorizontal(this->location(), location))
            {
                legalMove = true;
            }
        }
        
        // else if the square is in a horizontal line from the original location
        // and the diagonal path is clear then the move is legal
        else if (this->location().getY() == location.getY())
        {
            if (Board::getBoard().
                isClearVerticle(this->location(), location))
            {
                legalMove = true;
            }
        }
    }
    
    return legalMove;
}

/*
 * Method to get the value of the piece
 */
const int Rook::value() const
{
    return 5;
}

/*
 * Method to display the Rook
 */
const void Rook::display(ostream& output) const
{
    output << color() << string("R");
}