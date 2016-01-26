/*
 * Piece.h
 *
 * A class to represent a piece of a board game
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#ifndef __OOPChess__Piece__
#define __OOPChess__Piece__

#include <string>

using namespace std;

class Square;
class Player;
class Board;
class King;
class Game;

class Piece
{
public:
    // Constructors
    
    /*
     * Default constructor
     */
    Piece();
    
    /*
     * Create Piece with given color and square 
     * that it occupies
     *
     * @param initialSquare the square that the piece initially occupies
     * @param color the color of the piece
     */
    Piece(string& color);
    
    virtual ~Piece();
    
     /*
      * Gets the color of the piece
      *
      * @return a string representing the piece's color
      */
    virtual const string& color() const;
    
    /*
     * Gets the value of the piece
     *
     * @return an int representing the value of the piece
     */
    virtual const int value() const;
    
    /*
     * Gets the location of the piece
     * 
     * @return the Square that the piece is located at
     */
    virtual Square& location() const;
    
    /*
     * Moves the piece to a Square
     *
     * @param byPlayer the Player who moved the piece
     * @param to the Square to move the piece to
     *
     * @return true if the move was successful
     */
    virtual const bool moveTo(const Player& byPlayer, Square& to);
    
    /*
     * A method to display the piece
     */
    virtual const void display(ostream& output) const = 0;
    
    /*
     * A method to see if the piece can move to a Square
     *
     * @param location the location to check to see if the piece can move to
     *
     * @return true if the piece can move to the location
     */
    virtual const bool canMoveTo(Square& location) const = 0;
    
    /*
     * A method to set the location of a Piece 
     *
     * @param square the Square to set the piece's location to
     */
    virtual void setLocation(Square* square);
    
    /*
     * A method to see if a piece is on a square
     *
     * @return true if the piece is on a square
     */
    virtual const bool isOnSquare() const;

    
private:
    Square* _squareOccupies;
    string _color;
};

#endif /* defined(__OOPChess__Piece__) */
