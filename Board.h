/*
 * Board.h
 *
 * This class implements a Board class for a variety of games.
 *
 * Author:      David M. Hansen
 * Written:     10/5/2004
 *
 */

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>

using namespace std;

class Square;

class Board
{
public:
    // Accessors
    
    /**
     * @param x column of the square to return
     * @param y row of the square to return
     * @return a reference to square
     */
    Square& squareAt(int x, int y);
    
    /**
     * @return dimension of the board
     */
    int getDimension() const;
    
    /**
     * Check to see if the squares are 'verticle' and the path is clear
     *
     * @param from square to check from
     * @param to square to check to
     * @return true if squares are virticle and path is clear
     */
    bool isClearVerticle(Square& from, Square& to) const;
    
    /**
     * Check to see if the squares are 'horizontal' and the path is clear
     *
     * @param from square to check from
     * @param to square to check to
     * @return true if squares are horizontal and path is clear
     */
    bool isClearHorizontal(Square& from, Square& to) const;
    
    /**
     * Check to see if the squares are 'diagonal' and the path is clear
     *
     * @param from square to check from
     * @param to square to check to
     * @return true if squares are diagonal and path is clear
     */
    bool isClearDiagonal(Square& from, Square& to) const;
    
    /**
     * Display ourself on a stream
     *
     * @param output stream to display to
     */
    void display(ostream& output) const;
    
    /**
     * @return The Board
     */
    static Board& getBoard();
    
    /**
     * Define the ostream's << operator as a friend of this class
     * to allow this object to be printed to an output stream
     *
     * @param output stream to print to
     * @param board the Board to print
     * @return the stream printed to
     */
    friend ostream& operator<< (ostream& output, const Board& board);
    
    
private:
    
    // Constructor is private for singleton pattern
    /*
     * Default constructor
     */
    Board(int dimension = _DIMENSION);
    
    //Destructor
    ~Board();
    
    
    // Private attributes
    // A vector of vector of Piece for the board
    // Alternatively we could use Square _board[_DIMENSION][_DIMENSION]
    vector< vector<Square> > _squares;
    
    // Static class variables, one to hold the lone board and another to
    // define the default dimensions
    static Board _theBoard;
    static const int _DIMENSION;
    
}; // Board
#endif