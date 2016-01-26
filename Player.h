/*
 * Player.h
 *
 * A class to represent the player of a board game
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#ifndef __OOPChess__Player__
#define __OOPChess__Player__

#include <set>
#include <string>

using namespace std;

class King;
class Piece;
class Board;

class Player
{
public:
    // Constructors
    /*
     * Default constructor
     */
    Player();
    
    /*
     * Create a Player with the given name, king, 
     * and set of pieces
     * 
     * @param name name of the player
     * @param king the king that belongs to the player
     * @param pieces the pieces that belong to the player
     */
    Player(string name, King* myKing, set<Piece*>* myPieces);
    
    /*
     * Gets the name of the player
     *
     * @return the player's name
     */
    const string& getName() const;
    
    /*
     * Gets the player's pieces
     * 
     * @return a reference to the set of the player's pieces
     */
    const set<Piece*>& myPieces() const;
    
    /*
     * Gets the player's king
     *
     * @return a reference to the player's king
     */
    const King& myKing() const;
    
    /*
     * Gets the player's current score
     *
     * @return the player's score
     */
    const int score() const;
    
    /*
     * Moves a piece
     *
     * @return whether or not the move was successful
     */
    const bool makeMove() const;
    
    /*
     * Captures a piece
     *
     * @param aPiece a reference to the piece to capture
     */
    const void capture(Piece& aPiece) const;

private:
    // Private attributes
    string _name;
    King* _myKing;
    set<Piece*>* _myPieces;
    set<Piece*>* _capturedPieces;
    
};

#endif /* defined(__OOPChess__Player__) */
