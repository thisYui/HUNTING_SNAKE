#pragma once
#ifndef _MY_OBJECT
#define _MY_OBJECT

#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include <queue>

#define ONE_SECOND 1000

const int SNAKE_INIT_SIZE = 3;
const int SNAKE_MAX_SIZE = 8;
const int SNAKE_MIN_SPEED = 5;
const int SNAKE_MAX_SPEED = 10;

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
	bulletUp = L'⋒',
	bulletDown = L'⋓',
	bulletLeft = L'⋑',
	bulletRight = L'⋐',
	killer = L'☠',
	bullet = L'✶',
	food_1 = L'❤',
	food_2 = L'❣',
	mainDoor = L'⛶',
	o_1 = L'╬',
	o_2 = L'╩',
	o_3 = L'╦',
	o_4 = L'╠',
	o_5 = L'╣',
};
enum Word
{
	StartGame = 1,
	Setting = 2,
	History = 3,
	About = 4,
	Exit = 5,
	NewGame = 6,
	Continue = 7,
	Track = 8,
	Play = 9
};
struct point {
	int x, y;
};
struct snake
{
	point body[SNAKE_MAX_SIZE + 1] = { {0, 0} };
	int length;
	int speed;
	snake();
	void resetSnake();
	void updateSpeed();
};
struct food
{
	int x, y;
	std::queue<bool> bitbap;
	bool live;
	food();
	void makeFood(const snake& s, obstacle** theMap);
	void drawFood();
};
struct door
{
	point kernel;
	point wall[5];
	door();
	void makeDoor(const snake& s, obstacle**& theMap);
	//00
	//01
	//00
};
struct user
{
	std::string name;
	int score;
	int timePlay;
	user()
	{
		name = "";
		score = 0;
		timePlay = 0;
	}
	user(const std::string& _name, int _score, int _timePlay)
		: name(_name), score(_score), timePlay(_timePlay) {}
};

bool operator==(const point& a, const point& b);
std::ostream& operator<<(std::ostream& out, const Word& word);
Word operator++(Word& word, int);
Word& operator++(Word& word);
Word operator--(Word& word, int);
Word& operator--(Word& word);

bool eatFood(snake& snake, food& food, user* player);
void moveSnake(snake& snake, direction direction);
void drawSnake(const snake& snake);
void impactItself(const snake& snake, bool& isImpact);
void impactDoor(const snake& snake, const door& door, bool& isImpact, bool& next);
void impactWall(const snake& snake, obstacle** theMap, bool& isImpact);

namespace game
{
	namespace typeOne
	{
		void updateBullet(obstacle**& theMap, const food& f);
		void drawBullet();
		bool checkImpact(const snake& s);
	}
	namespace typeTwo
	{
		struct monster
		{
			point killer;
			int speed;
			monster();
			void moveKiller(const snake& s, obstacle** theMap);
			bool checkKill(const snake& s, obstacle** theMap) const;
			void drawKiller();
		};
	};
	namespace typeThree
	{
		struct monster
		{
			point killer;
			int speedKill;
			std::queue<point> listBullet;
			//2 phần tử liên tiếp là now và next
			int countTime;
			monster();
			void moveKiller(const snake& s, obstacle** theMap);
			bool checkKill(const snake& s, obstacle** theMap) const;
			void drawKiller();
			void makeBullet(const snake& s, obstacle** theMap);
			bool checkBullet(const snake& s, obstacle** theMap);
			void Draw_MoveBullet(obstacle** theMap);
		};
	};

	void drawMap(obstacle**& theMap, int x, int y, const int& level);
	void initMap(obstacle**& theMap);
	void initLevel_1(obstacle**& theMap);
	void initLevel_2(obstacle**& theMap);
	void initLevel_3(obstacle**& theMap);
	void initLevel_4(obstacle**& theMap);
	void initLevel_5(obstacle**& theMap);

	bool checkTarget(const snake& snake, user* player, const int level, const int theTime);
	bool conditionFood(const snake& snake, user* player, const int level);

}

#endif // !_MY_OBJECT