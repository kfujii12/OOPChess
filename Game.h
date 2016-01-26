/*
 * Game.h
 *
 * A class to represent a variety of games
 *
 * Author: 1668650
 * Created on: 3/15/15
 */

#ifndef __OOPChess__Game__
#define __OOPChess__Game__

#include <set>

using namespace std;

class Player;
class Square;
class Board;
class Piece;
class Rook;
class Knight;
class Bishop;
class King;
class Pawn;

class Game
{
public:
    
    // Accessors
    
    /*
     * Gets the next playerto go on the next turn
     *
     * @return a reference to the next player
     */
    static Player& getNextPlayer();
    
    /*
     * Initalize the board
     */
    static void initialize();
    
    /*
     * Gets a reference to the player that the given one 
     * is an opponent of
     * 
     * @param reference to the player to get opponents of
     */
    static Player& opponentOf(const Player& player);

private:
    // Constructor
    /*
     * Create a Game with a board
     */
    Game();
    
    // Destructor
    ~Game();
    
    static Board _theBoard;
    static set<Piece*>* _whitePieces;
    static set<Piece*>* _blackPieces;
    static Player* _player1;
    static Player* _player2;
    
}; // Game


#endif /* defined(__OOPChess__Game__) */
