/*
 * King.cpp
 *
 * A class to represent a king in a game of chess
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#include "King.h"
#include "Board.h"
#include "Square.h"

// Default constructor
King::King()
{
}

/*
 * Creates a King at the given inital square with the given color
 *
 * @param initialSquare the square the piece starts out on
 * @param color the color of the piece
 */
King::King(string& color) :
RestrictedPiece(color)
{
}

// Destructor
King::~King()
{
}

/*
 * Method to see if the King can move to the specified space
 *
 * @param location the Square to attempt to move the King to
 */
const bool King::canMoveTo(Square& location) const
{
    bool legalMove = false;
    
    // If the square is not already occupied by another piece and
    // that piece is not of the same color
    if (!location.occupied() ||
        (location.occupiedBy().color() != this->color()))
    {
        // A king can move one space diagonally, horizontally, or
        // vertically in any direction
        
        // Check to make sure the destination is only one square away from
        // the original location
        if ((abs(this->location().getY() - location.getY())) <= 1
                && (abs(this->location().getX() - location.getX()) <= 1))
        {
            // If the square is in a diagonal line from the original location
            // and the diagonal path is clear then the move is legal
            if (abs(this->location().getX() - location.getX()) ==
                abs(this->location().getY() - location.getY()))
            {
                if (Board::getBoard().
                    isClearDiagonal(this->location(), location))
                {
                    legalMove = true;
                }
            }
        
            // else if the square is in a horizontal line from the original location
            // and the diagonal path is clear then the move is legal
            else if (this->location().getX() == location.getX())
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
    }
    
    return legalMove;
}

/*
 * Method to get the value of the piece
 */
const int King::value() const
{
    // The king is basically the player's life,
    // so therefore the value of the king is life.
    return 42;
}

/*
 * Method to display the King
 */
const void King::display(ostream& output) const
{
    output << color() << string("K");
}