/*
 * Knight.h
 *
 * A class to represent a knight in a game of chess
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#ifndef __OOPChess__Knight__
#define __OOPChess__Knight__

#include "Piece.h"

class Square;
class Board;

class Knight : public Piece
{
public:
    // default constructor
    Knight();
    
    /*
     * Creates a Knight at the given inital square with the given color
     *
     * @param initialSquare the square the piece starts out on
     * @param color the color of the piece
     */
    Knight(string& color);
    
    // Destructor
    ~Knight();
    
    /*
     * Method to see if the bishop can move to the specified space
     *
     * @param location the Square to attempt to move the Knight to
     */
    const bool canMoveTo(Square& location) const;
    
    /*
     * Method to get the value of the piece
     */
    const int value() const;
    
    /*
     * Method to display the Knight
     */
    const void display(ostream& output) const;
};

#endif /* defined(__OOPChess__Knight__) */
