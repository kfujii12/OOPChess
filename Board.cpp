/*
 * Board.cpp
 *
 * This class implements a Board class for a variety of games.
 *
 * Author:      David M. Hansen
 * Written:     10/5/2004
 *
 */

#include "Board.h"
#include "Square.h"

// Constructors

// Default constructor
Board::Board(int dimension)
{
    // Create a vector of squares as a template that we can then copy
    // into our _board attribute, effectively populating the board with
    // copies of this row of squares
    vector<Square> rowTemplate(dimension);
    
    for (int i=0; i < dimension; i++)
    {
        _squares.push_back(rowTemplate);
    }
    
    for (int i=0; i < dimension; i++)
    {
        for (int j=0; j < dimension; j++) {
            Square* newSquare = new Square(i, j);
            _squares[i][j] = *newSquare;
        }
    }
}

// Destructor
Board::~Board()
{
}


// Accessors

// Return the square at x,y
Square& Board::squareAt(int x, int y)
{
    return _squares.at(x).at(y);
}


// Check for clear verticle
bool Board::isClearVerticle(Square& from, Square& to) const
{
    bool isClear = true;
    
    // variable to hold the direction that the loop should iterate in
    // (black side of the board to white or vice versa)
    int direction = 1;
    
    if (from.getX() > to.getX())
    {
        direction = -1;
    }
    
    // Iterate through all the squares between from and to
    // starting at the square that is one away from the from square
    // and toward the to square
    // then stopping at the square right before the to square
    for (int i = 1; i < abs(from.getX() - to.getX()); i++)
    {
        // If there is a square that is occupied
        // the verticle is not clear
        if (Board::getBoard().squareAt(from.getX() + i * direction,
                                       from.getY()).occupied())
        {
            isClear = false;
        }
    }
    return isClear;
}


// Check for clear horizontal
bool Board::isClearHorizontal(Square& from, Square& to) const
{
    bool isClear = true;
    
    // variable to hold the direction that the loop should iterate in
    // (black side of the board to white or vice versa)
    int direction = 1;
    
    if (from.getY() > to.getY())
    {
        direction = -1;
    }
    
    // Iterate through all the squares between from and to
    // starting at the square that is one away from the from square
    // and toward the to square
    // then stopping at the square right before the to square
    for (int i = 1; i < abs(from.getY() - to.getY()); i++)
    {
        // If there is a square that is occupied
        // the verticle is not clear
        if (Board::getBoard().squareAt(from.getX(),
                                       from.getY()
                                       + i * direction).occupied())
        {
            isClear = false;
        }
    }
    return isClear;
}


// Check for clear diagonal
bool Board::isClearDiagonal(Square& from, Square& to) const
{
    bool isClear = true;
    
    // variable to hold the direction that the loop should iterate in
    // (black side of the board to white or vice versa)
    int xDirection = 1;
    int yDirection = 1;
    
    if (from.getX() > to.getX())
    {
        xDirection = -1;
    }
    
    if (from.getY() > to.getY())
    {
        yDirection = -1;
    }
    
    // Iterate through all the squares between from and to
    // starting at the square that is one away from the from square
    // and toward the to square
    // then stopping at the square right before the to square
    for (int i = 1; i < abs(from.getY() - to.getY()); i++)
    {
        // If there is a square that is occupied
        // the verticle is not clear
        if (Board::getBoard().squareAt(from.getX() + i * xDirection,
                                       from.getY()
                                       + i * yDirection).occupied())
        {
            isClear = false;
        }
    }
    return isClear;

}


// Display the board
void Board::display(ostream& output) const
{
    output << "   a   b   c   d   e   f   g   h  " << endl;
    output << "  ";
    for (int i = 0; i < getDimension(); i++)
    {
        output << "----";
    }
    output << endl;
    for (int j = 0; j < getDimension(); j++)
    {
        output << (8 - j) << " ";
        for (int k = 0; k < getDimension(); k++)
        {
            _squares[j][k].display(output);
        }
        output  << " " << (8 - j);
        output << endl;
        output << "  ";
        for (int l = 0; l < getDimension(); l++)
        {
            output << "----";
        }
        output << endl;
    }
    output << "   a   b   c   d   e   f   g   h   " << endl;
}


// Get the reference to The Board
Board& Board::getBoard()
{
    return _theBoard;
}


// Return dimensions of the board
int Board::getDimension() const
{
    // Return the size of the board as the dimension
    return _squares.size();
}


// Print the board
ostream& operator<< (ostream& output, const Board& board)
{
    // Simply call our display method
    board.display(output);
    return output;
}


// Fixed size of the board - change this value to use a different size
// board
const int Board::_DIMENSION = 8;
Board Board::_theBoard; 