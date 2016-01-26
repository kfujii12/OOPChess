/*
 * Knight.cpp
 *
 * A class to represent a knight in a game of chess
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#include "Knight.h"
#include "Piece.h"
#include "Square.h"
#include "Board.h"

// Default constructor
Knight::Knight()
{
}

/*
 * Creates a Knight at the given inital square with the given color
 * 
 * @param initialSquare the square the piece starts out on
 * @param color the color of the piece
 */
Knight::Knight(string& color) :
Piece(color)
{
}

//Destructor
Knight::~Knight()
{
}

/*
 * Method to see if the Knight can move to the specified space
 *
 * @param location the Square to attempt to move the Knight to
 */
const bool Knight::canMoveTo(Square& location) const
{
    bool legalMove = false;
    
    // If the square is not already occupied by another piece and
    // that piece is not of the same color
    if (!location.occupied() ||
        (location.occupiedBy().color() != this->color()))
    {
        // A knight can move in an "L" shape in any direction
        
        // Check to see if the square is one away horizontally
        if (abs(this->location().getX() - location.getX()) == 1)
        {
            // If so, then check to see if it is two away vertically
            if (abs(this->location().getY() - location.getY()) == 2)
            {
                legalMove = true;
            }
        }
        
        // Else check to see if the square is one away vertically
        else if (abs(this->location().getY() - location.getY()) == 1)
        {
            // If so, then check to see if it is two away horizontally
            if (abs(this->location().getX() - location.getX()) == 2)
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
const int Knight::value() const
{
    return 3;
}

/*
 * Method to display the Knight
 */
const void Knight::display(ostream& output) const
{
    output << color() << string("N");
}