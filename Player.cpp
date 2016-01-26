/*
 * Player.cpp
 *
 * A class to represent the player of a board game
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#include "Player.h"
#include "King.h"
#include "Board.h"
#include "Square.h"

#include <stdexcept>

using namespace std;

// Constructors
// Default constructor
Player::Player()
{
}

/*
 * Create a Player with the given name, king,
 * and set of pieces
 *
 * @param name name of the player
 * @param king the king that belongs to the player
 * @param pieces the pieces that belong to the player
 */
Player::Player(string name, King* myKing, set<Piece*>* myPieces) :
_name(name), _myKing(myKing), _myPieces(myPieces)
{
    _capturedPieces = new set<Piece*>();
}

/*
 * Gets the name of the player
 *
 * @return the player's name
 */
const string& Player::getName() const
{
    return _name;
}

/*
 * Gets the player's pieces
 *
 * @return a reference to the set of the player's pieces
 */
const set<Piece*>& Player::myPieces() const
{
    return *_myPieces;
}

/*
 * Gets the player's king
 *
 * @return a reference to the player's king
 */
const King& Player::myKing() const
{
    return *_myKing;
}

/*
 * Gets the player's current score
 *
 * @return the player's score
 */
const int Player::score() const
{
    return 0;
}

/*
 * Moves a piece
 *
 * @return whether or not the move was successful
 */
const bool Player::makeMove() const
{
    int rowCoord1, rowCoord2;
    int translatedcolCoord1, translatedcolCoord2;
    char colCoord1, colCoord2;
    string color = "White";
    
    bool moveSuccessful = false;
    bool legalCoordinates = false;
    
    // Set the color string
    if (myKing().color() == "B")
    {
        color = "Black";
    }
    
    // While the coordinates entered are not legal or the move is not able
    // to be successfully executed, then keep prompting for coordinates
    while (!legalCoordinates || !moveSuccessful)
    {
        legalCoordinates = true;
        
        // Get the coordinates from the player
        cout << color << " enter move: ";
        cin >> colCoord1 >> rowCoord1 >> colCoord2 >> rowCoord2;
        
        // If the coordinates entered aren't able to be stored, then
        // prompt again and clear cin
        if (cin.fail())
        {
            cout << color << " enter move: ";
            cout << endl;
            cin.clear();
            cin >> colCoord1 >> rowCoord1 >> colCoord2 >> rowCoord2;
        }
        
        // Translate the y coordinates using ASCII math
        translatedcolCoord1 = (int)(colCoord1 - 'a');
        translatedcolCoord2 = (int)(colCoord2 - 'a');
        
        // Translate the x coordinates from algebraic notation to
        // the associated vector indexes
        rowCoord1 = 8 - rowCoord1;
        rowCoord2 = 8 - rowCoord2;

        // Try to access the square on the board
        // If it does not exist, then prompt again for a move
        try
        {
            // Check to see if a piece occupies the square and
            // if the piece is the players
            if (!Board::getBoard().
                squareAt(rowCoord1, translatedcolCoord1).occupied())
            {
                cout << "No piece on that square" << endl;
                legalCoordinates = false;
            }
            
            // Search the player's set of pieces to see if the one at the
            // source square belongs to them
            else if (myPieces().find(&Board::getBoard().
                                     squareAt(rowCoord1, translatedcolCoord1).
                                     occupiedBy()) == myPieces().end())
            {
                cout << "Not your piece" << endl;
                legalCoordinates = false;
            }
            
            // Check to see if a piece of the same color occupies the
            // destination square - this means the move isn't legal
            if (!Board::getBoard().
                squareAt(rowCoord2, translatedcolCoord2).occupied() &&
                myPieces().find(&Board::getBoard().
                    squareAt(rowCoord2, translatedcolCoord2).
                    occupiedBy()) != myPieces().end())
            {
                cout << "You already have a piece on that square" << endl;
                legalCoordinates = false;
            }

        } catch (out_of_range) {
            // Let the user know the coordinates are out of range
            cout << "Coordinates out of range" << endl;
            legalCoordinates = false;
        }
    
        // If the coordinates are legal, we now need to see if the move is
        // a legal one for the piece on the source square
        if (legalCoordinates)
        {
            // Ask the piece at (rowCoord1, colCoord1) if it can move to
            // (rowCoord2, colCoord2)
            moveSuccessful = Board::getBoard().
            squareAt(rowCoord1, translatedcolCoord1).
            occupiedBy().moveTo(*this, Board::getBoard().
                                squareAt(rowCoord2, translatedcolCoord2));
            
            // If the move wasn't successful, let the user know and
            // prompt for coordinates again
            if (!moveSuccessful)
            {
                cout << "Move was not allowed" << endl;
            }
        }
    }
    
    return moveSuccessful;
}

/*
 * Captures a piece
 *
 * @param aPiece a reference to the piece to capture
 */
const void Player::capture(Piece& aPiece) const
{
    // Add the piece captured to the set of this player's captured pieces
    _capturedPieces->insert(&aPiece);
    
    // The piece captured is no longer on the board, so set its location
    // to be null
    aPiece.setLocation(NULL);
}
