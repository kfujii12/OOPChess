/*
 * Bishop.cpp
 *
 * A class to represent a bishop in a game of chess
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#include "Bishop.h"
#include "Piece.h"
#include "Square.h"
#include "Board.h"

// Constructors

// Default constructor
Bishop::Bishop()
{
}

Bishop::Bishop(string& color) :
Piece(color)
{
}

// Destructor
Bishop::~Bishop()
{
}

/*
 * Method to see if the bishop can move to the specified space
 *
 * @param location the Square to attempt to move the Bishop to
 */
const bool Bishop::canMoveTo(Square& location) const
{
    bool legalMove = false;
    
    // If the square is not already occupied by another piece and
    // that piece is not of the same color
    if (!location.occupied() ||
        (location.occupiedBy().color() != this->color()))
    {
        // A bishop can move diagonally in any direction
        
        // If the square is in a diagonal line from the original location
        if (abs(this->location().getX() - location.getX()) ==
            abs(this->location().getY() - location.getY()))
        {
            // if the diagonal path is clear then the move is legal
            if (Board::getBoard().
                isClearDiagonal(this->location(), location))
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
const int Bishop::value() const
{
    return 3;
}

/*
 * Method to display the Bishop 
 */
const void Bishop::display(ostream& output) const
{
    output << color() << string("B");
}