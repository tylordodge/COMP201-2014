#include <list>
#include <vector>

#ifndef _MODEL_H
#define _MODEL_H

enum Direction { UP, DOWN, LEFT, RIGHT, DEAD };

typedef struct {
    int x;
    int y;
} Coordinate;

// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    Model(int w, int h);
    // Destructor deletes all dynamically allocated stuff
    ~Model();
    // Which way should the snake face?
    void go(Direction d);
    // Move foward one
    void crawl();
    // Is the game over?
    bool gameOver();
    // The snake
    std::list<Coordinate> snake;
	// The iterator
	std::list<Coordinate>::iterator it;
    // The food
    Coordinate food;
	//Coordinate spot
	Coordinate spot;
    // Which way is the snake moving?
    Direction direction;
	Direction last_d;
    // What's the width?
    int width;
    // What's the height?
    int height;
	
};

#endif