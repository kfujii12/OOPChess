/*
 * Queen.h
 *
 * A class to represent a queen in a game of chess
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#ifndef __OOPChess__Queen__
#define __OOPChess__Queen__

#include "Piece.h"

class Square;
class Board;

class Queen : public Piece
{
public:
    // Default constructor
    Queen();
    
    /*
     * Creates a Queen on the initial square of the given color
     *
     * @param initialSquare the square the piece starts out on
     * @param color the color of the piece
     */
    Queen(string& color);
    
    /*
     * Method to see if the bishop can move to the specified space
     *
     * @param location the Square to attempt to move the Queen to
     */
    const bool canMoveTo(Square& location) const;
    
    /*
     * Method to get the value of the piece
     */
    const int value() const;
    
    /*
     * Method to display the Queen
     */
    const void display(ostream& output) const;
};

#endif /* defined(__OOPChess__Queen__) */
