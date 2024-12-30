#include "object.h"
#include "console.h"

const char* LIST = "2312024523120258231202602312021923120213";
extern const int MATRIX_SIZE_WIDTH = 120;
extern const int MATRIX_SIZE_HEIGHT = 30;

snake::snake()
{
	length = SNAKE_INIT_SIZE;
	speed = SNAKE_MIN_SPEED;
	body[0].x = 5; body[1].x = 4; body[2].x = 3;
	body[0].y = 3; body[1].y = 3; body[2].y = 3;
}
void snake::resetSnake()
{
	for (int i = 0; i < length; i++)
	{
		body[i].x = 0;
		body[i].y = 0;
	}
	length = SNAKE_INIT_SIZE;
	speed = SNAKE_MIN_SPEED;
	body[0].x = 5; body[1].x = 4; body[2].x = 3;
	body[0].y = 3; body[1].y = 3; body[2].y = 3;
}
void snake::updateSpeed()
{
	if (length == SNAKE_MAX_SIZE - 2) speed = SNAKE_MAX_SPEED;
}
food::food()
{
	x = y = 0;
	live = false;
}
void food::makeFood(const snake& s, obstacle** theMap)
{
	if (live) return;
	srand(time(NULL));
	while (true)
	{
		x = rand() % (MATRIX_SIZE_WIDTH - MATRIX_SIZE_HEIGHT - 5) + 3;
		y = rand() % (MATRIX_SIZE_HEIGHT - 5) + 3;
		for (int i = 0; i < s.length; i++)
		{
			if (s.body[i].x == x && s.body[i].y == y) continue;
		}
		if (theMap[y - 1][x - 1] != obstacle::normal)
		{
			continue;
		}
		break;
	}
	live = true;
	bitbap.push(0); bitbap.push(1);
}
void food::drawFood()
{
	if (!live) return;

	gotoXY(x, y);
	int oldMode = _setmode(_fileno(stdout), _O_U16TEXT);
	setBackgroudAndText(0xfc);
	if (!bitbap.front())
		std::wcout << wchar_t(obstacle::food_1);
	else
		std::wcout << wchar_t(obstacle::food_2);
	setBackgroudAndText(0xf0);
	oldMode = _setmode(_fileno(stdout), oldMode);

	bool tmp = bitbap.front();
	bitbap.pop();
	bitbap.push(tmp);
}
door::door()
{
	kernel = { 0, 0 };
	wall[0] = { 0, 0 };
	wall[1] = { 0, 0 };
	wall[2] = { 0, 0 };
	wall[3] = { 0, 0 };
	wall[4] = { 0, 0 };
}
void door::makeDoor(const snake& s, obstacle**& theMap)
{
	srand(time(NULL));
	while (true)
	{
		kernel.x = rand() % (MATRIX_SIZE_WIDTH - MATRIX_SIZE_HEIGHT - 5) + 3;
		kernel.y = rand() % (MATRIX_SIZE_HEIGHT - 5) + 3;
		if (theMap[kernel.y - 1][kernel.x - 1] != obstacle::normal) continue;
		if (theMap[kernel.y][kernel.x - 2] != obstacle::normal) continue;
		if (theMap[kernel.y - 2][kernel.x - 2] != obstacle::normal) continue;
		if (theMap[kernel.y][kernel.x + 1] != obstacle::normal) continue;

		bool check = true;
		for (int i = 0; i < s.length; i++)
		{
			if (s.body[i].x == kernel.x && s.body[i].y == kernel.y)
			{
				check = false;
				break;
			}
		}
		for (int i = 0; i < 4; i++)
			if (!check) continue;
		break;
	}
	wall[0].x = kernel.x - 1; wall[0].y = kernel.y - 1;
	wall[1].x = kernel.x - 1; wall[1].y = kernel.y;
	wall[2].x = kernel.x - 1; wall[2].y = kernel.y + 1;
	wall[3].x = kernel.x; wall[3].y = kernel.y - 1;
	wall[4].x = kernel.x; wall[4].y = kernel.y + 1;

	theMap[wall[0].y - 1][wall[0].x - 1] = obstacle::up_left;
	theMap[wall[1].y - 1][wall[1].x - 1] = obstacle::vertical;
	theMap[wall[2].y - 1][wall[2].x - 1] = obstacle::down_left;
	theMap[wall[3].y - 1][wall[3].x - 1] = obstacle::horizontal;
	theMap[wall[4].y - 1][wall[4].x - 1] = obstacle::horizontal;

	int oldMode = _setmode(_fileno(stdout), _O_U16TEXT);

	gotoXY(kernel.x, kernel.y);
	std::wcout << wchar_t(obstacle::mainDoor);
	gotoXY(wall[0].x, wall[0].y);
	std::wcout << wchar_t(obstacle::up_left);
	gotoXY(wall[1].x, wall[1].y);
	std::wcout << wchar_t(obstacle::vertical);
	gotoXY(wall[2].x, wall[2].y);
	std::wcout << wchar_t(obstacle::down_left);
	gotoXY(wall[3].x, wall[3].y);
	std::wcout << wchar_t(obstacle::horizontal);
	gotoXY(wall[4].x, wall[4].y);
	std::wcout << wchar_t(obstacle::horizontal);

	oldMode = _setmode(_fileno(stdout), oldMode);
}

bool operator==(const point& a, const point& b)
{
	return a.x == b.x && a.y == b.y;
}
std::ostream& operator<<(std::ostream& out, const Word& word)
{
	switch (word)
	{
	case StartGame:
		out << "Start Game";
		break;
	case Setting:
		out << " Setting  ";
		break;
	case History:
		out << " History  ";
		break;
	case About:
		out << "  About   ";
		break;
	case Exit:
		out << "  Exit    ";
		break;
	case NewGame:
		out << "New Game";
		break;
	case Continue:
		out << "Continue";
		break;
	case Track:
		out << "Track";
		break;
	case Play:
		out << " Play";
		break;
	default:
		break;
	}
	return out;
}
Word operator++(Word& word, int)
{
	if (word == Exit) word = StartGame;
	else if (word == Continue) word = NewGame;
	else if (word == Play) word = Track;
	else word = static_cast<Word>(word + 1);
	return Word();
}
Word& operator++(Word& word)
{
	if (word == Exit) word = StartGame;
	else if (word == Continue) word = NewGame;
	else if (word == Play) word = Track;
	else word = static_cast<Word>(word + 1);
	return word;
}
Word operator--(Word& word, int)
{
	if (word == StartGame) word = Exit;
	else if (word == NewGame) word = Continue;
	else if (word == Track) word = Play;
	else word = static_cast<Word>(word - 1);
	return Word();
}
Word& operator--(Word& word)
{
	if (word == StartGame) word = Exit;
	else if (word == NewGame) word = Continue;
	else if (word == Track) word = Play;
	else word = static_cast<Word>(word - 1);
	return word;
}

bool eatFood(snake& snake, food& food, user* player)
{
	if (snake.body[0].x == food.x && snake.body[0].y == food.y)
	{
		snake.length++;
		player->score += 1;
		for (int i = snake.length; i > 0; i--)
		{
			snake.body[i] = snake.body[i - 1];
		}
		snake.body[0].x = food.x;
		snake.body[0].y = food.y;
		snake.updateSpeed();
		food.live = false;
		return true;
	}
	else if (snake.body[0].x == food.x + 1 && snake.body[0].y == food.y)
	{
		gotoXY(food.x, food.y);
		std::cout << " ";
		snake.length++;
		player->score += 1;
		for (int i = snake.length; i > 0; i--)
		{
			snake.body[i] = snake.body[i - 1];
		}
		snake.body[0].x = food.x + 1;
		snake.body[0].y = food.y;
		snake.updateSpeed();
		food.live = false;
		return true;
	}
	return false;
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

	drawSnake(snake);
}
void drawSnake(const snake& snake)
{
	int LENGTH = snake.length;
	setBackgroudAndText(0xfc);
	gotoXY(snake.body[0].x, snake.body[0].y);
	std::cout << LIST[0];
	setBackgroudAndText(0xf0);
	for (int i = 1; i < snake.length; i++)
	{
		gotoXY(snake.body[i].x, snake.body[i].y);
		std::cout << LIST[i % LENGTH];
	}
}
void impactItself(const snake& snake, bool& isImpact)
{
	point head = snake.body[0];
	for (int i = 1; i < snake.length; i++)
	{
		if (snake.body[i].x == head.x
			&& snake.body[i].y == head.y)
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
			return;
		}
	}
}
void impactWall(const snake& snake, obstacle** theMap, bool& isImpact)
{
	point head = snake.body[0];

	if (theMap[head.y - 1][head.x - 1] != obstacle::normal)
	{
		isImpact = true;
	}
}

namespace game
{
	static int Start_width = 2;
	static int Start_height = 2;
	static int end_width = MATRIX_SIZE_WIDTH - MATRIX_SIZE_HEIGHT - 3;
	static int end_height = MATRIX_SIZE_HEIGHT - 3;

	namespace typeOne
	{
		point Point[4] = { {Start_height, Start_width + (end_width - Start_width) / 5},
			{Start_height, Start_width + 3 * (end_width - Start_width) / 5},
			{end_height, Start_width + 2 * (end_width - Start_width) / 5},
			{end_height, Start_width + 4 * (end_width - Start_width) / 5} };

		void updateBullet(obstacle**& theMap, const food& f)
		{
			for (int i = 0; i < 4; i++)
			{
				gotoXY(Point[i].y + 1, Point[i].x + 1);
				std::cout << ' ';
			}
			for (int i = 0; i < 4; i++)
			{
				if (Point[i].x == f.x && Point[i].y == f.y)
				{
					if (i < 2) Point[i].x = Start_height;
					else Point[i].x = end_height;
				}
			}

			for (int i = 0; i < 2; i++)
			{
				if (theMap[Point[i].x + 1][Point[i].y + 1] == obstacle::normal) Point[i].x++;
				else Point[i].x = Start_height;
			}
			for (int i = 2; i < 4; i++)
			{
				if (theMap[Point[i].x - 1][Point[i].y - 1] == obstacle::normal) Point[i].x--;
				else Point[i].x = end_height;
			}

		}
		void drawBullet()
		{
			int oldMode = _setmode(_fileno(stdout), _O_U16TEXT);
			gotoXY(Point[0].y + 1, Point[0].x + 1);
			std::wcout << wchar_t(obstacle::bulletDown);
			gotoXY(Point[1].y + 1, Point[1].x + 1);
			std::wcout << wchar_t(obstacle::bulletDown);
			gotoXY(Point[2].y + 1, Point[2].x + 1);
			std::wcout << wchar_t(obstacle::bulletUp);
			gotoXY(Point[3].y + 1, Point[3].x + 1);
			std::wcout << wchar_t(obstacle::bulletUp);
			oldMode = _setmode(_fileno(stdout), oldMode);
		}
		bool checkImpact(const snake& s)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < s.length; j++)
				{
					if (s.body[j].x == Point[i].y + 1
						&& s.body[j].y == Point[i].x + 1)
					{
						return true;
					}
				}
			}
			return false;
		}
	}
	namespace typeTwo
	{
		monster::monster()
		{

			killer = { end_width - 5, end_height - 3 };
			speed = SNAKE_MIN_SPEED * 0.2;
		}
		void monster::moveKiller(const snake& s, obstacle** theMap)
		{
			point head = s.body[0];
			int x = killer.x - head.x;
			int y = killer.y - head.y;
			if (abs(x) > abs(y))
			{
				if (x > 0)
				{
					if (theMap[killer.y - 1][killer.x - 2] != obstacle::normal)
					{
						if (y > 0)
						{
							if (theMap[killer.y - 2][killer.x - 1] == obstacle::normal)
							{
								gotoXY(killer.x, killer.y);
								std::cout << " ";
								killer.y--;
							}
						}
						else if (y < 0)
						{
							if (theMap[killer.y][killer.x - 1] == obstacle::normal)
							{
								gotoXY(killer.x, killer.y);
								std::cout << " ";
								killer.y++;
							}
						}
					}
					else
					{
						gotoXY(killer.x, killer.y);
						std::cout << " ";
						killer.x--;
					}
				}
				else if (x < 0)
				{
					if (theMap[killer.y - 1][killer.x] != obstacle::normal)
					{
						if (y > 0)
						{
							if (theMap[killer.y - 2][killer.x - 1] == obstacle::normal)
							{
								gotoXY(killer.x, killer.y);
								std::cout << " ";
								killer.y--;
							}
						}
						else if (y < 0)
						{
							if (theMap[killer.y][killer.x - 1] == obstacle::normal)
							{
								gotoXY(killer.x, killer.y);
								std::cout << " ";
								killer.y++;
							}
						}
					}
					else
					{
						gotoXY(killer.x, killer.y);
						std::cout << " ";
						killer.x++;
					}
				}
			}
			else
			{
				if (y > 0)
				{
					if (theMap[killer.y - 2][killer.x - 1] != obstacle::normal)
					{
						if (x > 0)
						{
							if (theMap[killer.y - 1][killer.x - 2] == obstacle::normal)
							{
								gotoXY(killer.x, killer.y);
								std::cout << " ";
								killer.x--;
							}
						}
						else if (x < 0)
						{
							if (theMap[killer.y - 1][killer.x] == obstacle::normal)
							{
								gotoXY(killer.x, killer.y);
								std::cout << " ";
								killer.x++;
							}
						}
					}
					else
					{
						gotoXY(killer.x, killer.y);
						std::cout << " ";
						killer.y--;
					}
				}
				else if (y < 0)
				{
					if (theMap[killer.y][killer.x - 1] != obstacle::normal)
					{
						if (x > 0)
						{
							if (theMap[killer.y - 1][killer.x - 2] == obstacle::normal)
							{
								gotoXY(killer.x, killer.y);
								std::cout << " ";
								killer.x--;
							}
						}
						else if (x < 0)
						{
							if (theMap[killer.y - 1][killer.x] == obstacle::normal)
							{
								gotoXY(killer.x, killer.y);
								std::cout << " ";
								killer.x++;
							}
						}
					}
					else
					{
						gotoXY(killer.x, killer.y);
						std::cout << " ";
						killer.y++;
					}
				}
			}
		}
		bool monster::checkKill(const snake& s, obstacle** theMap) const
		{
			for (int i = 0; i < s.length; i++)
			{
				if (s.body[i] == killer)
				{
					return true;
				}
			}
			return false;
		}
		void monster::drawKiller()
		{
			int oldMode = _setmode(_fileno(stdout), _O_U16TEXT);
			gotoXY(killer.x, killer.y);
			std::wcout << wchar_t(obstacle::killer);
			oldMode = _setmode(_fileno(stdout), oldMode);
		}
	}
	namespace typeThree
	{
		monster::monster()
		{
			killer = { end_width - 5, end_height - 3 };
			speedKill = SNAKE_MIN_SPEED;
			countTime = 0;
			//5 bước di chuyển bắn 1 viên
		}
		void monster::moveKiller(const snake& s, obstacle** theMap)
		{
			point head = s.body[0];
			countTime++;
			int x = killer.x - head.x;
			int y = killer.y - head.y;
			if (abs(x) > abs(y))
			{
				if (x > 0)
				{
					if (theMap[killer.y - 1][killer.x - 2] != obstacle::normal)
					{
						if (y > 0)
						{
							if (theMap[killer.y - 2][killer.x - 1] == obstacle::normal)
							{
								gotoXY(killer.x, killer.y);
								std::cout << " ";
								killer.y--;
							}
						}
						else if (y < 0)
						{
							if (theMap[killer.y][killer.x - 1] == obstacle::normal)
							{
								gotoXY(killer.x, killer.y);
								std::cout << " ";
								killer.y++;
							}
						}
					}
					else
					{
						gotoXY(killer.x, killer.y);
						std::cout << " ";
						killer.x--;
					}
				}
				else if (x < 0)
				{
					if (theMap[killer.y - 1][killer.x] != obstacle::normal)
					{
						if (y > 0)
						{
							if (theMap[killer.y - 2][killer.x - 1] == obstacle::normal)
							{
								gotoXY(killer.x, killer.y);
								std::cout << " ";
								killer.y--;
							}
						}
						else if (y < 0)
						{
							if (theMap[killer.y][killer.x - 1] == obstacle::normal)
							{
								gotoXY(killer.x, killer.y);
								std::cout << " ";
								killer.y++;
							}
						}
					}
					else
					{
						gotoXY(killer.x, killer.y);
						std::cout << " ";
						killer.x++;
					}
				}
			}
			else
			{
				if (y > 0)
				{
					if (theMap[killer.y - 2][killer.x - 1] != obstacle::normal)
					{
						if (x > 0)
						{
							if (theMap[killer.y - 1][killer.x - 2] == obstacle::normal)
							{
								gotoXY(killer.x, killer.y);
								std::cout << " ";
								killer.x--;
							}
						}
						else if (x < 0)
						{
							if (theMap[killer.y - 1][killer.x] == obstacle::normal)
							{
								gotoXY(killer.x, killer.y);
								std::cout << " ";
								killer.x++;
							}
						}
					}
					else
					{
						gotoXY(killer.x, killer.y);
						std::cout << " ";
						killer.y--;
					}
				}
				else if (y < 0)
				{
					if (theMap[killer.y][killer.x - 1] != obstacle::normal)
					{
						if (x > 0)
						{
							if (theMap[killer.y - 1][killer.x - 2] == obstacle::normal)
							{
								gotoXY(killer.x, killer.y);
								std::cout << " ";
								killer.x--;
							}
						}
						else if (x < 0)
						{
							if (theMap[killer.y - 1][killer.x] == obstacle::normal)
							{
								gotoXY(killer.x, killer.y);
								std::cout << " ";
								killer.x++;
							}
						}
					}
					else
					{
						gotoXY(killer.x, killer.y);
						std::cout << " ";
						killer.y++;
					}
				}
			}
		}
		bool monster::checkKill(const snake& s, obstacle** theMap) const
		{
			point head = s.body[0];
			if (head == killer)
			{
				return true;
			}
			return false;
		}
		void monster::drawKiller()
		{
			int oldMode = _setmode(_fileno(stdout), _O_U16TEXT);
			gotoXY(killer.x, killer.y);
			std::wcout << wchar_t(obstacle::killer);
			oldMode = _setmode(_fileno(stdout), oldMode);
		}

		void monster::makeBullet(const snake& s, obstacle** theMap)
		{
			if (countTime == 50)
			{
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -1; j <= 1; j++)
					{
						if (i == 0 && j == 0) continue;
						listBullet.push(killer);
						listBullet.push(point{ killer.x + i, killer.y + j });
					}
				}
				countTime = 0;
			}
			else if (countTime % 10 == 0)
			{
				point bullet = killer;
				point head = s.body[0];
				int x = head.x - killer.x;
				int y = head.y - killer.y;

				if (x > 0) bullet.x++;
				else if (x < 0) bullet.x--;
				if (y > 0) bullet.y++;
				else if (y < 0) bullet.y--;

				listBullet.push(killer);
				listBullet.push(bullet);
			}
		}
		bool monster::checkBullet(const snake& s, obstacle** theMap)
		{
			int n = listBullet.size();
			n /= 2;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < s.length; j++)
				{
					point tmp1 = listBullet.front();
					listBullet.pop();
					point tmp2 = listBullet.front();
					listBullet.pop();
					if (s.body[j] == tmp1)
					{
						return true;
					}
					listBullet.push(tmp1);
					listBullet.push(tmp2);
				}
			}
			return false;
		}
		void monster::Draw_MoveBullet(obstacle** theMap)
		{
			int oldMode = _setmode(_fileno(stdout), _O_U16TEXT);
			int n = listBullet.size();
			n /= 2;
			while (n--)
			{
				point previous = listBullet.front();
				listBullet.pop();
				point now = listBullet.front();
				listBullet.pop();
				if (previous.x != killer.x || previous.y != killer.y)
				{
					gotoXY(previous.x, previous.y);
					std::wcout << L" ";
					if (theMap[now.y - 1][now.x - 1] == obstacle::normal)
					{
						gotoXY(now.x, now.y);
						std::wcout << wchar_t(obstacle::bullet);
					}
				}

				if (theMap[now.y - 1][now.x - 1] == obstacle::normal)
				{
					listBullet.push(now);
					listBullet.push(point{ 2 * now.x - previous.x,
						2 * now.y - previous.y });
				}
			}
			oldMode = _setmode(_fileno(stdout), oldMode);
		}
	}

	void drawMap(obstacle**& theMap, int x, int y, const int& level)
	{
		int oldMode = _setmode(_fileno(stdout), _O_U16TEXT);
		for (int i = 0; i < MATRIX_SIZE_HEIGHT; i++)
		{
			gotoXY(x, y + i);
			for (int j = 0; j < MATRIX_SIZE_WIDTH; j++)
			{
				std::wcout << wchar_t(theMap[i][j]);
			}
		}

		gotoXY(((MATRIX_SIZE_WIDTH - MATRIX_SIZE_HEIGHT) - 7) / 2, 1);
		std::wcout << L"LEVEL " << level;

		oldMode = _setmode(_fileno(stdout), oldMode);
	}
	void initMap(obstacle**& theMap)
	{
		for (int i = 0; i < MATRIX_SIZE_HEIGHT; i++)
		{
			for (int j = 0; j < MATRIX_SIZE_WIDTH; j++)
			{
				theMap[i][j] = obstacle::normal;
			}
		}
	}
	void initLevel_1(obstacle**& theMap)
	{

		for (int i = 0; i < MATRIX_SIZE_WIDTH; i++)
		{
			theMap[0][i] = obstacle::horizontal;
			theMap[1][i] = obstacle::horizontal;
			theMap[MATRIX_SIZE_HEIGHT - 1][i] = obstacle::horizontal;
			theMap[MATRIX_SIZE_HEIGHT - 2][i] = obstacle::horizontal;
		}
		for (int i = 0; i < MATRIX_SIZE_HEIGHT; i++)
		{
			theMap[i][0] = obstacle::vertical;
			theMap[i][MATRIX_SIZE_WIDTH - MATRIX_SIZE_HEIGHT - 1] = obstacle::vertical;
			theMap[i][MATRIX_SIZE_WIDTH - MATRIX_SIZE_HEIGHT] = obstacle::vertical;
			theMap[i][MATRIX_SIZE_WIDTH - 1] = obstacle::vertical;
		}
		for (int i = 1; i < MATRIX_SIZE_HEIGHT - 1; i++)
		{
			theMap[i][1] = obstacle::vertical;
			theMap[i][MATRIX_SIZE_WIDTH - MATRIX_SIZE_HEIGHT - 2] = obstacle::vertical;
			theMap[i][MATRIX_SIZE_WIDTH - MATRIX_SIZE_HEIGHT + 1] = obstacle::vertical;
			theMap[i][MATRIX_SIZE_WIDTH - 2] = obstacle::vertical;
		}

		theMap[0][0] = obstacle::up_left;
		theMap[0][MATRIX_SIZE_WIDTH - MATRIX_SIZE_HEIGHT - 1] = obstacle::up_right;
		theMap[MATRIX_SIZE_HEIGHT - 1][0] = obstacle::down_left;
		theMap[MATRIX_SIZE_HEIGHT - 1][MATRIX_SIZE_WIDTH - MATRIX_SIZE_HEIGHT - 1] = obstacle::down_rigth;
		theMap[1][1] = obstacle::up_left;
		theMap[1][MATRIX_SIZE_WIDTH - MATRIX_SIZE_HEIGHT - 2] = obstacle::up_right;
		theMap[MATRIX_SIZE_HEIGHT - 2][1] = obstacle::down_left;
		theMap[MATRIX_SIZE_HEIGHT - 2][MATRIX_SIZE_WIDTH - MATRIX_SIZE_HEIGHT - 2] = obstacle::down_rigth;

		theMap[0][MATRIX_SIZE_WIDTH - MATRIX_SIZE_HEIGHT] = obstacle::up_left;
		theMap[0][MATRIX_SIZE_WIDTH - 1] = obstacle::up_right;
		theMap[MATRIX_SIZE_HEIGHT - 1][MATRIX_SIZE_WIDTH - MATRIX_SIZE_HEIGHT] = obstacle::down_left;
		theMap[MATRIX_SIZE_HEIGHT - 1][MATRIX_SIZE_WIDTH - 1] = obstacle::down_rigth;
		theMap[1][MATRIX_SIZE_WIDTH - MATRIX_SIZE_HEIGHT + 1] = obstacle::up_left;
		theMap[1][MATRIX_SIZE_WIDTH - 2] = obstacle::up_right;
		theMap[MATRIX_SIZE_HEIGHT - 2][MATRIX_SIZE_WIDTH - MATRIX_SIZE_HEIGHT + 1] = obstacle::down_left;
		theMap[MATRIX_SIZE_HEIGHT - 2][MATRIX_SIZE_WIDTH - 2] = obstacle::down_rigth;
	}
	void initLevel_2(obstacle**& theMap)
	{
		initLevel_1(theMap);

		for (int i = Start_height; i <= end_height; i++)
		{
			theMap[i][Start_width + (end_width - Start_width) / 2] = obstacle::vertical;
		}
		for (int i = Start_width; i <= end_width; i++)
		{
			theMap[Start_height + (end_height - Start_height) / 2][i] = obstacle::horizontal;
		}
		for (int i = 4; i < 10; i++)
		{
			theMap[Start_height + i][Start_width + (end_width - Start_width) / 2] = obstacle::normal;
			theMap[end_height - i][Start_width + (end_width - Start_width) / 2] = obstacle::normal;
		}
		for (int i = 8; i < 24; i++)
		{
			theMap[Start_height + (end_height - Start_height) / 2][Start_width + i] = obstacle::normal;
			theMap[Start_height + (end_height - Start_height) / 2][end_width - i] = obstacle::normal;
		}

		theMap[Start_height + (end_height - Start_height) / 2][Start_width + (end_width - Start_width) / 2] = obstacle::o_1;
		theMap[Start_height - 1][Start_width + (end_width - Start_width) / 2] = obstacle::o_3;
		theMap[end_height + 1][Start_width + (end_width - Start_width) / 2] = obstacle::o_2;
		theMap[Start_height + (end_height - Start_height) / 2][Start_width - 1] = obstacle::o_4;
		theMap[Start_height + (end_height - Start_height) / 2][end_width + 1] = obstacle::o_5;
	}
	void initLevel_3(obstacle**& theMap)
	{
		initLevel_1(theMap);

		theMap[Start_height - 1][Start_width + (end_width - Start_width) / 5] = obstacle::o_3;
		theMap[Start_height - 1][Start_width + 3 * (end_width - Start_width) / 5] = obstacle::o_3;
		theMap[end_height + 1][Start_width + 2 * (end_width - Start_width) / 5] = obstacle::o_2;
		theMap[end_height + 1][Start_width + 4 * (end_width - Start_width) / 5] = obstacle::o_2;

	}
	void initLevel_4(obstacle**& theMap)
	{
		initLevel_1(theMap);
		initLevel_2(theMap);
	}
	void initLevel_5(obstacle**& theMap)
	{
		initLevel_1(theMap);
	}

	bool checkTarget(const snake& snake, user* player, const int level, const int theTime)
	{
		switch (level)
		{
		case 1:
			if (snake.length > SNAKE_MAX_SIZE - 1)
			{
				return true;
			}
			return false;
			break;
		case 2:
			if (snake.length > SNAKE_MAX_SIZE - 1)
			{
				return true;
			}
			return false;
			break;
		case 3:
			if (snake.length > SNAKE_MAX_SIZE - 1)
			{
				return true;
			}
			return false;
			break;
		case 4:
			if (snake.length > 5 && (player->timePlay - theTime) > 30)
			{
				return true;
			}
			return false;
			break;
		case 5:
			if (player->timePlay - theTime > 60)
			{
				return true;
			}
			return false;
			break;
		default:
			break;
		}
	}
	bool conditionFood(const snake& snake, user* player, const int level)
	{
		switch (level)
		{
		case 1:
			if (snake.length > SNAKE_MAX_SIZE - 1)
			{
				return true;
			}
			return false;
			break;
		case 2:
			if (snake.length > SNAKE_MAX_SIZE - 1)
			{
				return true;
			}
			return false;
			break;
		case 3:
			if (snake.length > SNAKE_MAX_SIZE - 1)
			{
				return true;
			}
			return false;
			break;
		case 4:
			if (snake.length > 5)
			{
				return true;
			}
			return false;
			break;
		case 5:
			return true;
			break;
		default:
			return true;
			break;
		}
	}
}