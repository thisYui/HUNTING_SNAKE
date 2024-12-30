#pragma once
#ifndef _MY_UI
#define _MY_UI

#include "object.h"
#include <conio.h>
#include <thread>
#include <chrono>
#include <mutex>
namespace alphabet
{
	void printA(int x, int y);
	void printB(int x, int y);
	void printC(int x, int y);
	void printD(int x, int y);
	void printE(int x, int y);
	//void printF();
	void printG(int x, int y);
	void printH(int x, int y);
	void printI(int x, int y);
	//void printJ();
	void printK(int x, int y);
	void printL(int x, int y);
	void printM(int x, int y);
	void printN(int x, int y);
	void printO(int x, int y);
	void printP(int x, int y);
	//void printQ();
	void printR(int x, int y);
	void printS(int x, int y);
	void printT(int x, int y);
	void printU(int x, int y);
	void printV(int x, int y);
	void printW(int x, int y);
	//void printX();
	//void printY(int x, int y);
	//void printZ();
	//void printSpace();
}

void playMusix(const char* path, bool status);// phát nhạc
void fillFullScreen(int color);// tô màu full màn hình
char init();// khởi tạo console
void inforName(user*& player);//nhap ten nguoi choi
Word printMenu();// menu thứ nhất
Word printPlay();// menu thứ hai
void setMusic(bool& statusTrack, bool& statusSound, bool& quit, bool& playing);//on off musix
void printRecord(user* listUser, int countUser, bool& quit, bool& playing);//in lịch sử
void printAboutUs(bool& quit, bool& playing);//giới thiệu thông tin nhóm
char printLose(user* User, int level);//thông báo thua
char printWin(user* User, int level);//thông báo thắng
char printContinue(user* User, int level);//tiếp tục hay không
void endGame(bool& _quit_, bool& _Playing_);//thoát game

//-----THREAD-----
void _printInformation(const int x, const int y, bool& _Playing_, user* User, const snake& Snake,
	const bool& next, const int level);
//thread thông tin người chơi
void _snakePlay(snake& _snake_, food& _food_, door& door, obstacle** theMap, const direction& dir,
	user* player, bool& playing, const int& level, bool& next);
//thread rắn
void _monsterPlay(snake& _snake_, obstacle** theMap, food& Food, bool& playing, const int& level, bool& next);
//thread killer

#endif // !_MY_UI