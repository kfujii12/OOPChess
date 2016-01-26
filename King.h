/*
 * King.h
 *
 * A class to represent a king in a game of chess
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#ifndef __OOPChess__King__
#define __OOPChess__King__

#include "RestrictedPiece.h"

class Board;
class Square;

class King : public RestrictedPiece
{
public:
    
    // Default constructor
    King();
    
    /*
     * Creates a King at the given inital square with the given color
     *
     * @param initialSquare the square the piece starts out on
     * @param color the color of the piece
     */
    King(string& color);
    
    // Destructor
    ~King();
    
    /*
     * Method to see if the bishop can move to the specified space
     *
     * @param location the Square to attempt to move the King to
     */
    const bool canMoveTo(Square& location) const;
    
    /*
     * Method to get the value of the piece
     */
    const int value() const;
    
    /*
     * Method to display the King
     */
    const void display(ostream& output) const;
};


#endif /* defined(__OOPChess__King__) */
