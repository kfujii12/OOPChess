/*
 * Piece.cpp
 *
 * A class to represent a piece of a board game
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#include "Piece.h"
#include "Square.h"
#include "Player.h"
#include "Board.h"
#include "King.h"
#include "Game.h"

#include <iostream>

// Constructors

/*
 * Default constructor
 */
Piece::Piece()
{
}

/*
 * Create Piece with given color and square
 * that it occupies
 *
 * @param initialSquare the square that the piece initially occupies
 * @param color the color of the piece
 */
Piece::Piece(string& color) :
_color(color)
{
}

/*
 * Destructor
 */
Piece::~Piece()
{
}

/*
 * Gets the color of the piece
 *
 * @return a string representing the piece's color
 */
const string& Piece::color() const
{
    return _color;
}

/*
 * Gets the value of the piece
 *
 * @return an int representing the value of the piece
 */
const int Piece::value() const
{
    return 0;
}

/*
 * Gets the location of the piece
 *
 * @return the Square that the piece is located at
 */
Square& Piece::location() const
{
    return *_squareOccupies;
}

/*
 * Moves the piece to a Square
 *
 * @param byPlayer the Player who moved the piece
 * @param to the Square to move the piece to
 *
 * @return true if the move was successful
 */
const bool Piece::moveTo(const Player& byPlayer, Square& to)
{
    bool moved = canMoveTo(to);
    set<Piece*>::iterator pieceIt;
    Square* originalLocation;
    Piece* toOriginalOccupier;
    
    // If the piece is in the collection of the player who called the move
    // and the move is legal, then we can move the piece to the square
    // capture piece if there is one on the square
    if (moved)
    {
        originalLocation = &(Piece::location());
        toOriginalOccupier = &to.occupiedBy();
        
        // We will essentially be making the move, evaluating if it is legal,
        // then moving the piece back to where it originally was
        setLocation(&to);
        to.setOccupier(this);
        originalLocation->setOccupier(NULL);
        
        
        // Now if it was a legal move, then check to see if making the move
        // puts the player whose turn it is in check
        
        // While the move is still legal,
        // Iterate through all of the opposite player's pieces and see
        // if they can move to the space that this player's king occupies
        pieceIt = Game::opponentOf(byPlayer).myPieces().begin();
        while (moved &&
               pieceIt != Game::opponentOf(byPlayer).myPieces().end())
        {
            // If the piece the iterator is pointing to is currently on
            // a square, would not be captured by the current piece
            // after the move, and piece can move to the square the King
            // occupies, then the move cannot be executed
            
            if ((*pieceIt)->isOnSquare() &&
                &(*pieceIt)->location() != &to &&
                (*pieceIt)->canMoveTo(byPlayer.myKing().location()))
            {
                moved = false;
                
            }
            pieceIt++;
        }
        
        // Move the piece back to the original space
        setLocation(originalLocation);
        to.setOccupier(toOriginalOccupier);
        originalLocation->setOccupier(this);
        
        // If it is still legal for the move to be executed, then move the
        // piece for real
        if (moved)
        {
            // If the square is occupied, capture the piece
            if (to.occupied())
            {
                byPlayer.capture(to.occupiedBy());
            }
            
            // Move the piece for realsies now
            this->setLocation(&to);
            to.setOccupier(this);
            originalLocation->setOccupier(NULL);
            
            // Check to see if the other player's king is now in check
            if (this->canMoveTo(Game::opponentOf(byPlayer).
                                myKing().location()))
            {
                cout << "Check" << endl;
            }
        }
    }
    return moved;
}

/*
 * A method to see if a piece is on a square
 *
 * @return true if the piece is on a square
 */
const bool Piece::isOnSquare() const
{
    return _squareOccupies;
}

/*
 * A method to set the location of a Piece
 *
 * @param square the Square to set the piece's location to
 */
void Piece::setLocation(Square* square)
{
    _squareOccupies = square;
}