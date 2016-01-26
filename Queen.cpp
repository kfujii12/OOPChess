/*
 * Queen.cpp
 *
 * A class to represent a queen in a game of chess
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#include "Queen.h"
#include "Piece.h"
#include "Square.h"
#include "Board.h"

// Default constructor
Queen::Queen()
{
}

/*
 * Creates a Queen on the initial square of the given color
 * 
 * @param initialSquare the square the piece starts out on
 * @param color the color of the piece
 */
Queen::Queen(string& color) :
Piece(color)
{
}

/*
 * Method to see if the Queen can move to the specified space
 *
 * @param location the Square to attempt to move the Queen to
 */
const bool Queen::canMoveTo(Square& location) const
{
    bool legalMove = false;
    
    // If the square is not already occupied by another piece and
    // that piece is not of the same color
    if (!location.occupied() ||
        (location.occupiedBy().color() != this->color()))
    {
        // A queen can move diagonally, horizontally, or vertically in
        // any direction
        
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
        
        // else if the square is in a horizontal line from the original
        // location and the diagonal path is clear then the move is legal
        else if (this->location().getX() == location.getX())
        {
            if (Board::getBoard().
                isClearHorizontal(this->location(), location))
            {
                legalMove = true;
            }
        }
        
        // else if the square is in a horizontal line from the original
        // location and the diagonal path is clear then the move is legal
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
const int Queen::value() const
{
    return 9;
}

/*
 * Method to display the Queen
 */
const void Queen::display(ostream& output) const
{
    output << color() << string("Q");
}