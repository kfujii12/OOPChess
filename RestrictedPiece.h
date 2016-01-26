/*
 * RestrictedPiece.h
 *
 * A class to represent a restricted piece in a game of chess
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#ifndef __OOPChess__RestrictedPiece__
#define __OOPChess__RestrictedPiece__

#include "Piece.h"

class RestrictedPiece : public Piece
{
public:
    // Default constructor
    RestrictedPiece();
    
    /*
     * Creates a RestrictedPiece at the given inital square with the given color
     *
     * @param initialSquare the square the piece starts out on
     * @param color the color of the piece
     */
    RestrictedPiece(string& color);

    // Destructor
    virtual ~RestrictedPiece();
    
    /*
     * Method to move a piece to a space
     * 
     * @param byPlayer the player who moves the piece
     * @param to the square to move the piece to
     * 
     * @return true if the move is successful
     */
    virtual const bool moveTo(Player& byPlayer, Square& to);
    
protected:
    /*
     * Method to see if the piece was moved
     *
     * @return true if the piece was moved
     */
    virtual const bool hasMoved() const;
    
private:
    bool _moved;
};

#endif /* defined(__OOPChess__RestrictedPiece__) */
