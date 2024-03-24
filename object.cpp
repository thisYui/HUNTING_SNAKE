#include "object.h"
#include "console.h"
#include <io.h>
#include <fcntl.h>

const char* LIST = "2312024523120258231202602312021923120213";
extern const int MAXTRIX_SIZE_WIDTH = 60;
extern const int MAXTRIX_SIZE_HEIGHT = 20;

snake::snake()
{
	length = SNAKE_INIT_SIZE;
	speed = SNAKE_MIN_SPEED;
	for (int i = 0; i < length; i++)
	{
		body[i].x = 0;
		body[i].y = 0;
	}
}
snake::~snake()
{
	delete[] body;
}
food::food(snake s)
{
	srand(time(NULL));
	while (true)
	{
		x = rand() % (FOOD_SIZE - 1) + 1;
		y = rand() % (FOOD_SIZE - 1) + 1;
		for (int i = 0; i < s.length; i++)
		{
			if (s.body[i].x == x && s.body[i].y == y) continue;
		}
		break;
	}
	gotoXY(x, y);
	std::cout << " ";
}
door::door()
{
	srand(time(NULL));
	kernel.x = rand() % (FOOD_SIZE - 1) + 1;
	kernel.y = rand() % (FOOD_SIZE - 1) + 1;
	wall[0].x = kernel.x - 1; wall[0].y = kernel.y - 1;
	wall[1].x = kernel.x - 1; wall[1].y = kernel.y;
	wall[2].x = kernel.x - 1; wall[2].y = kernel.y + 1;
	wall[3].x = kernel.x; wall[3].y = kernel.y - 1;
	wall[4].x = kernel.x; wall[4].y = kernel.y + 1;

	gotoXY(kernel.x, kernel.y);
	std::cout << " ";
	for (int i = 0; i < 5; i++)
	{
		gotoXY(wall[i].x, wall[i].y);
		std::cout << " ";
	}
}

bool operator==(const point& a, const point& b)
{
	return a.x == b.x && a.y == b.y;
}
std::ostream& operator<<(std::ostream& out, const Word& word) 
{
	switch (word)
	{
	case StarGame:
		out << "Star Game";
		break;
	case Setting:
		out << "Setting";
		break;
	case History:
		out << "History";
		break;
	case About:
		out << "About";
		break;
	case Exit:
		out << "Exit";
		break;
	case NewGame:
		out << "New Game";
		break;
	case Continue:
		out << "Continue";
		break;
	default:
		break;
	}
	return out;
}
Word operator++(Word& word, int)
{
	if (word == Exit) word = StarGame;
	else if (word == Continue) word = NewGame;
	else word = static_cast<Word>(word + 1);
	return Word();
}

void eatFood(snake& snake, food food, direction direction)
{
	if (snake.body[0].x == food.x && snake.body[0].y == food.y)
	{
		snake.length++;
		for (int i = snake.length; i > 0; i--)
		{
			snake.body[i] = snake.body[i - 1];
		}
		snake.body[0].x = food.x;
		snake.body[0].y = food.y;
	}
}
void moveSnake(snake& snake, direction direction)
{
	gotoXY(snake.body[snake.length - 1].x, snake.body[snake.length - 1].y);
	std::cout << " ";
	for (int i = snake.length; i > 0; i--)
	{
		snake.body[i] = snake.body[i - 1];

	}
	switch (direction) {
	case direction::UP:
		snake.body[0].y--;
		break;
	case direction::DOWN:
		snake.body[0].y++;
		break;
	case direction::LEFT:
		snake.body[0].x--;
		break;
	case direction::RIGHT:
		snake.body[0].x++;
		break;
	}
}
void drawSnake(const snake& snake)
{
	int LENGTH = snake.length;
	int speed = ONE_SECOND / snake.speed;

	for (int i = 0; i < snake.length; i++)
	{
		gotoXY(snake.body[i].x, snake.body[i].y);
		std::cout << LIST[i % LENGTH];
		Sleep(speed);
	}
}
void impactItself(const snake& snake, bool& isImpact)
{
	point head = snake.body[0];
	for (int i = 1; i < snake.length; i++)
	{
		if (snake.body[i].x == head.x && snake.body[i].y == head.y)
		{
			isImpact = true;
			break;
		}
	}
}
void impactDoor(const snake& snake, const door& door, bool& isImpact, bool& next)
{
	point head = snake.body[0];

	if (head == door.kernel)
	{
		next = true;
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		if (head == door.wall[i])
		{
			isImpact = true;
			break;
		}
	}
}

namespace game
{
	void drawMap(obstacle** theMap, int x, int y)
	{
		int oldMode = _setmode(_fileno(stdout), _O_U16TEXT);
		for (int i = 0; i < MAXTRIX_SIZE_HEIGHT; i++)
		{
			gotoXY(x, y + i);
			for (int j = 0; j < MAXTRIX_SIZE_WIDTH; j++)
			{
				std::wcout << wchar_t(theMap[i][j]);
			}
		}
		oldMode = _setmode(_fileno(stdout), oldMode);
	}
	void initMap(obstacle** theMap)
	{
		for (int i = 0; i < MAXTRIX_SIZE_HEIGHT; i++)
		{
			for (int j = 0; j < MAXTRIX_SIZE_WIDTH; j++)
			{
				theMap[i][j] = obstacle::normal;
			}
		}
	}
	void initLevel_1(obstacle** theMap)
	{
		for (int i = 0; i < MAXTRIX_SIZE_WIDTH; i++)
		{
			theMap[0][i] = obstacle::horizontal;
			theMap[1][i] = obstacle::horizontal;
			theMap[MAXTRIX_SIZE_HEIGHT - 1][i] = obstacle::horizontal;
			theMap[MAXTRIX_SIZE_HEIGHT - 2][i] = obstacle::horizontal;
		}
		for (int i = 0; i < MAXTRIX_SIZE_HEIGHT; i++)
		{
			theMap[i][0] = obstacle::vertical;
			theMap[i][MAXTRIX_SIZE_WIDTH - MAXTRIX_SIZE_HEIGHT - 1] = obstacle::vertical;
			theMap[i][MAXTRIX_SIZE_WIDTH - MAXTRIX_SIZE_HEIGHT] = obstacle::vertical;
			theMap[i][MAXTRIX_SIZE_WIDTH - 1] = obstacle::vertical;
		}
		for (int i = 1; i < MAXTRIX_SIZE_HEIGHT - 1; i++)
		{
			theMap[i][1] = obstacle::vertical;
			theMap[i][MAXTRIX_SIZE_WIDTH - MAXTRIX_SIZE_HEIGHT - 2] = obstacle::vertical;
			theMap[i][MAXTRIX_SIZE_WIDTH - MAXTRIX_SIZE_HEIGHT + 1] = obstacle::vertical;
			theMap[i][MAXTRIX_SIZE_WIDTH - 2] = obstacle::vertical;
		}

		theMap[0][0] = obstacle::up_left;
		theMap[0][MAXTRIX_SIZE_WIDTH - MAXTRIX_SIZE_HEIGHT - 1] = obstacle::up_right;
		theMap[MAXTRIX_SIZE_HEIGHT - 1][0] = obstacle::down_left;
		theMap[MAXTRIX_SIZE_HEIGHT - 1][MAXTRIX_SIZE_WIDTH - MAXTRIX_SIZE_HEIGHT - 1] = obstacle::down_rigth;
		theMap[1][1] = obstacle::up_left;
		theMap[1][MAXTRIX_SIZE_WIDTH - MAXTRIX_SIZE_HEIGHT - 2] = obstacle::up_right;
		theMap[MAXTRIX_SIZE_HEIGHT - 2][1] = obstacle::down_left;
		theMap[MAXTRIX_SIZE_HEIGHT - 2][MAXTRIX_SIZE_WIDTH - MAXTRIX_SIZE_HEIGHT - 2] = obstacle::down_rigth;

		theMap[0][MAXTRIX_SIZE_WIDTH - MAXTRIX_SIZE_HEIGHT] = obstacle::up_left;
		theMap[0][MAXTRIX_SIZE_WIDTH - 1] = obstacle::up_right;
		theMap[MAXTRIX_SIZE_HEIGHT - 1][MAXTRIX_SIZE_WIDTH - MAXTRIX_SIZE_HEIGHT] = obstacle::down_left;
		theMap[MAXTRIX_SIZE_HEIGHT - 1][MAXTRIX_SIZE_WIDTH - 1] = obstacle::down_rigth;
		theMap[1][MAXTRIX_SIZE_WIDTH - MAXTRIX_SIZE_HEIGHT + 1] = obstacle::up_left;
		theMap[1][MAXTRIX_SIZE_WIDTH - 2] = obstacle::up_right;
		theMap[MAXTRIX_SIZE_HEIGHT - 2][MAXTRIX_SIZE_WIDTH - MAXTRIX_SIZE_HEIGHT + 1] = obstacle::down_left;
		theMap[MAXTRIX_SIZE_HEIGHT - 2][MAXTRIX_SIZE_WIDTH - 2] = obstacle::down_rigth;
	}

	void initLevel_2(obstacle** theMap)
	{
	}

	void initLevel_3(obstacle** theMap)
	{
	}

	void initLevel_4(obstacle** theMap)
	{
	}

	void initLevel_5(obstacle** theMap)
	{
	}

	void impactWall(const snake& snake, const obstacle** theMap, bool& isImpact)
	{
		point head = snake.body[0];
		if (theMap[head.y][head.x] != obstacle::normal)
		{
			isImpact = true;
		}
	}

	void drawWin()
	{
	}

}