/*
 * Pawn.h
 *
 * A class to represent a pawn in a game of chess
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#ifndef __OOPChess__Pawn__
#define __OOPChess__Pawn__

#include "RestrictedPiece.h"

class Queen;
class Square;
class Board;
class Piece;
class Game;
class Player;
class King;

class Pawn : public RestrictedPiece
{
public:
    // Default constructor
    Pawn();
    
    /*
     * Creates a Pawn at the given inital square with the given color
     *
     * @param initialSquare the square the piece starts out on
     * @param color the color of the piece
     */
    Pawn(string& color);
    
    // Destructor
    ~Pawn();
    
    /*
     * Method to display the Pawn
     */
    const void display(ostream& output) const;
    
    /*
     * Method to determine if the pawn can move to a specified Square
     *
     * @param location the square to validate
     *
     * @return true if the move can be made
     */
    const bool canMoveTo(Square& location) const;
    
    /*
     * Moves the pawn to a Square
     *
     * @param byPlayer the Player who moved the piece
     * @param to the Square to move the piece to
     *
     * @return true if the move was successful
     */
    const bool moveTo(const Player& byPlayer, Square& to);
    
    /*
     * Method to set the location of a pawn
     *
     * @param square the square to set the location 
     *        of the pawn and its delegate Queen if needed
     */
    void setLocation(Square* square);
    
    /*
     * Method to get the value of the piece
     */
    const int value() const;
    
private:
    Queen* _delegate;
};


#endif /* defined(__OOPChess__Pawn__) */
