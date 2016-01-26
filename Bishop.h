/*
 * Bishop.h
 *
 * A class to represent a bishop in a game of chess
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#ifndef __OOPChess__Bishop__
#define __OOPChess__Bishop__

#include "Piece.h"

class Square;
class Board;

class Bishop : public Piece
{
public:
    // Constructor
    
    /*
     * Default constructor
     */
    Bishop();
    
    /*
     * Create a Bishop with a given initialSquare and color
     */
    Bishop(string& color);
    
    // Deconstructor
    ~Bishop();
    
    /*
     * Method to see if the bishop can move to the specified space
     *
     * @param location the Square to attempt to move the Bishop to
     */
    const bool canMoveTo(Square& location) const;
    
    /*
     * Method to get the value of the piece
     */
    const int value() const;
    
    /*
     * Method to display the Bishop
     */
    const void display(ostream& output) const;
};

#endif /* defined(__OOPChess__Bishop__) */
