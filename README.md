WHITE:(COLOR=0)

PAWN    -> 1
KNIGHT  -> 2
BISHOP  -> 3
ROOK    -> 4
QUEEN   -> 5
KING    -> 6

BLACK:(COLOR=1)

PAWN    -> 11
KNIGHT  -> 12
BISHOP  -> 13
ROOK    -> 14
QUEEN   -> 15
KING    -> 16


Compile with g++ chess.cpp -o chess -lSDL2 -lSDL2_image


Run using any of the following:


1.    ./chess W     ->   Player vs engine with player having white pieces
2.    ./chess B     ->   Player vs engine with player having black pieces
3.    ./chess M     ->   Player vs Player
4.    ./chess E     ->   Engine vs Engine

