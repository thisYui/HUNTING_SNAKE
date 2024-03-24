#pragma once
#ifndef _MY_OBJECT
#define _MY_OBJECT

#include <iostream>
#include <string>
#define ONE_SECOND 1000
#define SNAKE_COLOR 10
#define FOOD_COLOR 12

const int FOOD_SIZE = 12;
const int SNAKE_INIT_SIZE = 3;
const int SNAKE_MAX_SIZE = 100;
const int SNAKE_MIN_SPEED = 10;
const int SNAKE_MAX_SPEED = 100;

enum direction {
	UP, DOWN, LEFT, RIGHT
};
enum obstacle
{
	normal = L' ',
	up_left = L'╔',
	up_right = L'╗',
	down_left = L'╚',
	down_rigth = L'╝',
	horizontal = L'═',
	vertical = L'║',
	o_1 = L'╬',
	o_2 = L'╩',
	o_3 = L'╦',
	o_4 = L'╠',
	o_5 = L'╣',
	o_6 = L'╭',
	o_7 = L'╮',
	o_8 = L'╯',
	o_9 = L'╰',
	o_10 = L'-',
	o_11 = L'|',
	door_1 = L'❶',
	door_2 = L'❷',
	door_3 = L'❸',
	door_4 = L'❹',
	door_5 = L'❺',
};
enum Word
{
	StarGame = 1,
	Setting = 2,
	History = 3,
	About = 4,
	Exit = 5,
	NewGame = 6,
	Continue = 7
};
struct point {
	int x, y;
};
struct snake
{
	point body[SNAKE_MAX_SIZE];
	int length;
	int speed;
	snake();
	~snake();
};
struct food
{
	int x, y;
	food(snake s);
};
struct door
{
	point kernel;
	point wall[5];
	door();
	//00
	//01
	//00
};
struct user
{
	std::string name;
	int score;
	double timePlay;
	user()
	{
		name = "";
		score = 0;
		timePlay = 0.0;
	}
	user(const std::string& _name, int _score, double _timePlay)
		: name(_name), score(_score), timePlay(_timePlay) {}
};

bool operator==(const point& a, const point& b);
std::ostream& operator<<(std::ostream& out, const Word& word);
Word operator++(Word& word, int);

void eatFood(snake& snake, food food, direction direction);//hàm ?n th?c ?n
void moveSnake(snake& snake, direction direction);//hàm di chuy?n r?n
void drawSnake(const snake& snake);//hàm v? r?n
void impactItself(const snake& snake, bool& isImpact);//hàm va ch?m v?i chính nó
void impactDoor(const snake& snake, const door& door, bool& isImpact, bool& next);//hàm va ch?m v?i c?a

namespace game
{
	void drawMap(obstacle** theMap, int x, int y);
	void initMap(obstacle** theMap);
	void initLevel_1(obstacle** theMap);
	void initLevel_2(obstacle** theMap);
	void initLevel_3(obstacle** theMap);
	void initLevel_4(obstacle** theMap);
	void initLevel_5(obstacle** theMap);

	void impactWall(const snake& snake, const obstacle** theMap, bool& isImpact);

	void drawWin();
}

#endif // !_MY_OBJECT