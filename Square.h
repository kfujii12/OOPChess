//
//  Square.h
//  OOPChess
//
//  Created by 1668650 on 3/15/15.
//  Copyright (c) 2015 1668650. All rights reserved.
//


/*
 * A bogus Square class just for compilation purposes
 */
#ifndef __OOPChess__Square__
#define __OOPChess__Square__

#include <iostream>

using namespace std;

class Player;
class King;
class Board;
class Square;
class Piece;

class Square
{
public:
    // Constructors
    /*
     * Square default constructor
     */
    Square();
    
    /*
     * Create Square with given x and y coordinate
     *
     * @param x the x coordinate of the player
     * @param y the y coordinate of the player
     */
    Square(int x, int y);
    
    // Destructor
    ~Square();
    
    /*
     * Method to get the x coordinate of the square
     *
     * @return an int that represents the x coordinate 
     */
    const int getX() const;
    
    /*
     * Method to get the y corrdinate of the square
     *
     * @return an int that represents the y coordinate
     */
    const int getY() const;
    
    /*
     * Method to get whether or not a square is occupied
     *
     * @return true if occupied
     */
    const bool occupied() const;
    
    /*
     * Method to get what piece occupies the square
     *
     * @return the piece occupying the square
     */
    Piece& occupiedBy() const;
    
    /*
     * Method to set what piece occupies the space
     *
     * @param the piece to occupy the space
     */
    void setOccupier(Piece* piece);
    
    void display(ostream& output) const;
    
    friend ostream& operator<< (ostream& output, const Square& square);

private:
    // private attributes
    int _x;
    int _y;
    Piece* _pieceOccupiedBy;
};

#endif /* defined(__OOPChess__Square__) */
