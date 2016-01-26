/*
 * Square.cpp
 *
 * A class to represent a square on a board
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#include "Square.h"
#include "Piece.h"

// Constructors

/*
 * Square default constructor
 */
Square::Square()
{
}

/*
 * Create Square with given x and y coordinate
 *
 * @param x the x coordinate of the player
 * @param y the y coordinate of the player
 */
Square::Square(int x, int y)
{
    _x = x;
    _y = y;
}

// Destructor
Square::~Square()
{
}

/*
 * Method to get the x coordinate of the square
 *
 * @return an int that represents the x coordinate
 */
const int Square::getX() const
{
    return _x;
}

/*
 * Method to get the y corrdinate of the square
 *
 * @return an int that represents the y coordinate
 */
const int Square::getY() const
{
    return _y;
}

/*
 * Method to get whether or not a square is occupied
 *
 * @return true if occupied
 */
const bool Square::occupied() const
{
    bool result = true;
    if (!_pieceOccupiedBy)
    {
        result = false;
    }
    return result;
}

/*
 * Method to get what piece occupies the square
 *
 * @return the piece occupying the square
 */
Piece& Square::occupiedBy() const
{
    return *_pieceOccupiedBy;
}

/*
 * Method to set what piece occupies the space
 *
 * @param the piece to occupy the space
 */
void Square::setOccupier(Piece* piece)
{
    _pieceOccupiedBy = piece;
}

void Square::display(ostream& output) const
{
    output << "|";
    // if the square is occupied, then display the piece
    if (occupied())
    {
        occupiedBy().display(output);
    }
    // otherwise just display two blank spaces
    else
    {
        output << "  ";
    }
    output << "|";
}

ostream& operator<< (ostream& output, const Square& square)
{
    return output;
}


