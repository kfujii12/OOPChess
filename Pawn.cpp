/*
 * Pawn.cpp
 *
 * A class to represent a pawn in a game of chess
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#include "Pawn.h"
#include "Queen.h"
#include "Square.h"
#include "Board.h"
#include "Piece.h"
#include "Game.h"
#include "Player.h"
#include "King.h"

#define WHITE_DIRECTION -1
#define BLACK_DIRECTION 1
#define BLACK_END 7
#define WHITE_END 0

// Default constructor
Pawn::Pawn()
{
}

/*
 * Creates a Pawn at the given inital square with the given color
 *
 * @param initialSquare the square the piece starts out on
 * @param color the color of the piece
 */
Pawn::Pawn(string& color) :
RestrictedPiece(color), _delegate(NULL)
{
}

// Destructor
Pawn::~Pawn()
{
    delete _delegate;
}

/*
 * Method to display the Pawn
 */
const void Pawn::display(ostream& output) const
{
    if (_delegate)
    {
        _delegate->display(output);
    }
    else
    {
        output << color() << string("P");
    }
}

/*
 * Moves the pawn to a Square
 *
 * @param byPlayer the Player who moved the piece
 * @param to the Square to move the piece to
 *
 * @return true if the move was successful
 */
const bool Pawn::moveTo(const Player& byPlayer, Square& to)
{
    bool moveSuccessful = Piece::moveTo(byPlayer, to);
    
    // default end of board is black
    int boardEndIndex = BLACK_END;
    
    string delegateColor = color();
    
    // Define the direction of black pieces and white pieces
    if (color() == "W")
    {
        boardEndIndex = WHITE_END;
    }
    
    // If the move is successful, then check to see if we need to manage
    // the delegate queen
    if (moveSuccessful)
    {
        // Create a delegate Queen for the pawn if the pawn has reached
        // the other end of the board from which it started
        if (!_delegate && to.getX() == boardEndIndex)
        {
            _delegate = new Queen(delegateColor);
        }
        
        // If the delegate exists, then set its location to be the same as
        // the pawn
        if (_delegate)
        {
            _delegate->setLocation(&to);
            
            // Check to see if the other player's king is now in check due
            // to the delegate
            if (this->canMoveTo(Game::opponentOf(byPlayer).
                                myKing().location()))
            {
                cout << "Check" << endl;
            }

        }
    }
    
    return moveSuccessful;
}

/*
 * Method to determine if the pawn can move to a specified Square
 *
 * @param location the square to validate
 *
 * @return true if the move can be made
 */
const bool Pawn::canMoveTo(Square& location) const
{
    // default direction is for the black
    int direction = BLACK_DIRECTION;
    
    // Define the direction of black pieces and white pieces
    if (color() == "W")
    {
        direction = WHITE_DIRECTION;
    }
    
    bool legalMove = false;
    
    // If the pawn has been upgraded to a delegate piece, then call the
    // delegate Queen's canMoveTo function
    
    if (_delegate)
    {
        legalMove = _delegate->canMoveTo(location);
    }
    
    else
    {
        // If the square is not already occupied by another piece and
        // that piece is of the same color
        
        if (!location.occupied())
        {
            // The pawn can only move straight forward unless the move is
            // diagonal
            if (location.getY() == this->location().getY())
            {
                // if the pawn has moved
                if (!RestrictedPiece::hasMoved())
                {
                    // then a legal move is to move one or two spaces forward
                    if (location.getX() == this->location().getX()
                        + 2 * direction)
                    {
                        // but it's only legal if there's not a piece
                        // between the current one and the location
                        if (!(Board::getBoard().
                              squareAt(this->location().getX() + 1
                                       * direction,
                                       this->location().getY()).occupied()))
                        {
                            legalMove = true;
                        }
                    }
                    
                }
                // if the space is unoccupied and is one in
                // front of the current space the move is legal
                if (location.getX() == this->location().getX()
                    + 1 * direction)
                {
                    legalMove = true;
                }
            }
            
        }
        
        // if a piece of the opposite color is diagonally forward from
        // the pawn
        else if (location.getX() == this->location().getX() + 1 * direction
                 && (location.getY() == this->location().getY() + 1 ||
                  location.getY() == this->location().getY() - 1)
                 && location.occupiedBy().color() != color())
        {
            if (location.occupied()
                && location.occupiedBy().color() != color())
            {
                // then it is a legal move to move diagonally and capture that
                // piece
                legalMove = true;
            }
        }

    }
    
    return legalMove;
}

/*
 * Method to set the location of a pawn
 *
 * @param square the square to set the location
 *        of the pawn and its delegate Queen if needed
 */
void Pawn::setLocation(Square* square)
{
    RestrictedPiece::setLocation(square);
    
    // set location of delegate if it exists
    if (_delegate)
    {
        _delegate->setLocation(square);
    }
}

/*
 * Method to get the value of the piece
 */
const int Pawn::value() const
{
    return 1;
}


