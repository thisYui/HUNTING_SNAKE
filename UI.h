#pragma once
#ifndef _MY_UI
#define _MY_UI

#include "object.h"
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
	//void printL();
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

void soundTrack(bool& status);// âm thanh nền
void soudPlay(bool& status);// âm thanh khi chơi
void fillFullScreen(int color);// tô màu full màn hình
void init();// khởi tạo console
void inforName(user* &player, int x, int y);//nhap ten nguoi choi
Word printMenu(int x, int y);
Word printPlay(int x, int y);
void setMusic(bool& statusTrack, bool& statusSound, int x, int y);
void printRecord(user* listUser, int countUser, int x, int y);
void printAboutUs(int x, int y);
void printPause(int x, int y);
void printGameOver(int x, int y);
void printWin(int x, int y);
bool printContinue(int x, int y);
bool printResult(user* User, int level, int x, int y, bool win);
void printInformation(int x, int y, bool& _Playing_, user* User , snake& Snake);
void endGame(bool& _quit_, bool& _Playing_);


#endif // !_MY_UI