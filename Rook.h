/*
 * Rook.h
 *
 * A class to represent a rook in a game of chess
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#ifndef __OOPChess__Rook__
#define __OOPChess__Rook__

#include "RestrictedPiece.h"

class Square;
class Board;

class Rook : public RestrictedPiece
{
public:
    // Default constructor
    Rook();
    
    /*
    * Creates a Rook at the given inital square with the given color
    *
    * @param initialSquare the square the piece starts out on
    * @param color the color of the piece
    */
    Rook(string& color);
    
    // Destructor
    ~Rook();
    
    /*
     * Method to see if the bishop can move to the specified space
     *
     * @param location the Square to attempt to move the Rook to
     */
    const bool canMoveTo(Square& location) const;
    
    /*
     * Method to get the value of the piece
     */
    const int value() const;
    
    /*
     * Method to display the Rook
     */
    const void display(ostream& output) const;
};

#endif /* defined(__OOPChess__Rook__) */
