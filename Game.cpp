/*
 * Game.cpp
 *
 * A class to represent various games
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#include "Game.h"
#include "Square.h"
#include "Board.h"
#include "Player.h"
#include "Piece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"

// global variable
Player* _nextPlayer;

// Constructors

// Default constructor
Game::Game()
{
}

//Destructor should destroy whitePieces, blackPieces, Board, and Players
Game::~Game()
{
}

// Accessors

/*
 * Gets the next playerto go on the next turn
 *
 * @return a reference to the next player
 */
Player& Game::getNextPlayer()
{
    return *_nextPlayer;
}

/*
 * Initalize the board
 */
void Game::initialize()
{
    // variables representing black and white
    string black = "B";
    string white = "W";
    
    // create black and white piece sets
    _blackPieces = new set<Piece*>();
    _whitePieces = new set<Piece*>();
    King* whiteKing = new King(white);
    King* blackKing = new King(black);
    _nextPlayer = NULL;
    
    // put black pieces on board
    Board::getBoard().squareAt(0, 0).
        setOccupier((new Rook(black)));
    Board::getBoard().squareAt(0, 0).occupiedBy().
        setLocation(&Board::getBoard().squareAt(0, 0));
    Board::getBoard().squareAt(0, 1).
        setOccupier((new Knight(black)));
    Board::getBoard().squareAt(0, 1).occupiedBy().
        setLocation(&Board::getBoard().squareAt(0, 1));
    Board::getBoard().squareAt(0, 2).
        setOccupier((new Bishop(black)));
    Board::getBoard().squareAt(0, 2).occupiedBy().
        setLocation(&Board::getBoard().squareAt(0, 2));
    Board::getBoard().squareAt(0, 3).
        setOccupier((new Queen(black)));
    Board::getBoard().squareAt(0, 3).occupiedBy().
        setLocation(&Board::getBoard().squareAt(0, 3));
    Board::getBoard().squareAt(0, 4).
        setOccupier(blackKing);
    Board::getBoard().squareAt(0, 4).occupiedBy().
        setLocation(&Board::getBoard().squareAt(0, 4));
    Board::getBoard().squareAt(0, 5).
        setOccupier((new Bishop(black)));
    Board::getBoard().squareAt(0, 5).occupiedBy().
        setLocation(&Board::getBoard().squareAt(0, 5));
    Board::getBoard().squareAt(0, 6).
        setOccupier((new Knight(black)));
    Board::getBoard().squareAt(0, 6).occupiedBy().
        setLocation(&Board::getBoard().squareAt(0, 6));
    Board::getBoard().squareAt(0, 7).
        setOccupier((new Rook(black)));
    Board::getBoard().squareAt(0, 7).occupiedBy().
        setLocation(&Board::getBoard().squareAt(0, 7));
    
    // put black pawns on the board
    for (int i = 0; i < 8; i++)
    {
        Board::getBoard().squareAt(1, i).
            setOccupier((new Pawn(black)));
        Board::getBoard().squareAt(1, i).occupiedBy().
            setLocation(&Board::getBoard().squareAt(1, i));

    }
    
    // add black pieces to black set of pieces
    // j starts at 6 because the black pieces are in the 6th and 7th row
    // of the board (if the indexes start at 0)
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // need to ask if occupied
            // Casting to Piece* to get rid of const
            _blackPieces->insert(&(Board::getBoard().squareAt(i, j).occupiedBy()));
        }
    }
    
    // put white pieces on board
    Board::getBoard().squareAt(7, 0).
        setOccupier((new Rook(white)));
    Board::getBoard().squareAt(7, 0).occupiedBy().
        setLocation(&Board::getBoard().squareAt(7, 0));
    Board::getBoard().squareAt(7, 1).
        setOccupier((new Knight(white)));
    Board::getBoard().squareAt(7, 1).occupiedBy().
        setLocation(&Board::getBoard().squareAt(7, 1));
    Board::getBoard().squareAt(7, 2).
        setOccupier((new Bishop(white)));
    Board::getBoard().squareAt(7, 2).occupiedBy().
        setLocation(&Board::getBoard().squareAt(7, 2));
    Board::getBoard().squareAt(7, 3).
        setOccupier((new Queen(white)));
    Board::getBoard().squareAt(7, 3).occupiedBy().
        setLocation(&Board::getBoard().squareAt(7, 3));
    Board::getBoard().squareAt(7, 4).
        setOccupier(whiteKing);
    Board::getBoard().squareAt(7, 4).occupiedBy().
        setLocation(&Board::getBoard().squareAt(7, 4));
    Board::getBoard().squareAt(7, 5).
        setOccupier((new Bishop(white)));
    Board::getBoard().squareAt(7, 5).occupiedBy().
        setLocation(&Board::getBoard().squareAt(7, 5));
    Board::getBoard().squareAt(7, 6).
        setOccupier((new Knight(white)));
    Board::getBoard().squareAt(7, 6).occupiedBy().
        setLocation(&Board::getBoard().squareAt(7, 6));
    Board::getBoard().squareAt(7, 7).
        setOccupier((new Rook(white)));
    Board::getBoard().squareAt(7, 7).occupiedBy().
        setLocation(&Board::getBoard().squareAt(7, 7));
    
    // put white pawns on board
    for (int i = 0; i < 8; i++)
    {
        Board::getBoard().squareAt(6, i).
            setOccupier((new Pawn(white)));
        Board::getBoard().squareAt(6, i).occupiedBy().
            setLocation(&Board::getBoard().squareAt(6, i));
    }
    
    // add white pieces to black set of pieces
    for (int i = 6; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // need to ask if occupied
            // Casting to Piece* to get rid of const
            _whitePieces->insert(&(Board::getBoard().squareAt(i, j).occupiedBy()));
        }
    }
    
    // Create players
    _player1 = new Player(string("Player 1"), whiteKing, _whitePieces);
    _player2 = new Player(string("Player 2"), blackKing, _blackPieces);
    
    _nextPlayer = _player1;
    
    // Display the initial state of the board
    Board::getBoard().display(cout);
    
    while (true)
    {
        // Have the player make a move
        getNextPlayer().makeMove();
        
        // Set the next player
        _nextPlayer = &opponentOf(getNextPlayer());
        
        // Display the board again
        Board::getBoard().display(cout);
    }
}

/*
 * Gets a reference to the player that the given one
 * is an opponent of
 *
 * @param reference to the player to get opponents of
 */
Player& Game::opponentOf(const Player& player)
{
    Player* opponent;
    if (player.myKing().color() == "B")
    {
        opponent =  _player1;
    }
    else
    {
        opponent = _player2;
    }
    
    return *opponent;
}

set<Piece*>* Game::_whitePieces;
set<Piece*>* Game::_blackPieces;
Player* Game::_player1;
Player* Game::_player2;
