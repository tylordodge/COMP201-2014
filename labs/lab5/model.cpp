#include "model.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

// Constructor initializes the object
Model::Model(int w, int h) {
    width = w;
    height = h;
    Coordinate head;
    Coordinate tail;
	
    direction = RIGHT;
    head.x = 1;
    head.y = 0;
    tail.x = 0;
    tail.y = 0;
    food.x = 5;
    food.y = 10;
    snake.push_front(head);
    snake.push_back(tail);
	srand(time(0));
	vector<int> last_d;
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
}

bool Model::gameOver() {
    return snake.empty() || snake.size() == width * height;
}

// Which way should the snake face?
void Model::go(Direction d) {
    direction = d;
}

// Move foward
void Model::crawl() {
    Coordinate front = snake.front();
	Coordinate back = snake.back();
	Coordinate spot;
	
	for (list<Coordinate>::iterator it=++(snake.begin()); it!=snake.end(); it++){
		if (it->x == front.x && it->y == front.y){
			direction = DEAD;
		}
	}
	
	
	if(front.x == -1 || front.x == 65 || front.y == -1 || front.y == 49){
		direction = DEAD;
	}
	
	for (list<Coordinate>::iterator it = ++(snake.begin()); it != snake.end(); it++){
		
		
	}
	
	
	if (direction == UP && last_d == DOWN){
		direction = DOWN;
	}
	else if (direction == DOWN && last_d == UP){
		direction = UP;
	}
	else if (direction == RIGHT && last_d == LEFT){
		direction = LEFT;
	}
	else if (direction == LEFT && last_d == RIGHT){
		direction = RIGHT;
	}
	
	
//	enum Direction { UP, DOWN, LEFT, RIGHT, DEAD };
    switch(direction) {
		case UP:
			front.y--; 
			break;
		case DOWN: 
			front.y++; 
			break;
		case LEFT: 
			front.x--; 
			break;
		case RIGHT: 
			front.x++; 			
			break;
	//shrink the snake to nothing.
		case DEAD: 
			while (!snake.empty()){
				snake.pop_front(); 
			}
			break;
	}
	
    // TODO: Colliding with the perimeter of the screen should set direction to DEAD
    // When DEAD, the snake slowly shrinks down to nothing
    
    if (direction != DEAD) {
        snake.push_front(front);
    }

    // TODO: Colliding with food grows the snake (so don't pop_back in that case)
    // TODO: Also, colliding with food should cause us to place the food somewhere
    // else, but not anywhere on the snake.
	
	if (front.x == food.x && front.y == food.y){
		snake.push_back(back);
		food.x = rand() % 64;
		food.y = rand() % 48;
	}
	
	//TODO: snake should not double back on itself
	//TODO: Snake cannot collide with itself
	
    snake.pop_back();
	last_d = direction;
	
}
