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
	/*void printO();
	void printP();
	void printQ();*/
	void printR(int x, int y);
	void printS(int x, int y);
	void printT(int x, int y);
	void printU(int x, int y);
	/*void printV();
	void printW();
	void printX();
	void printY();
	void printZ();*/
	//void printSpace();
}

void soundTrack(bool& status);
void soudPlay(bool& status);
void fillFullScreen(int color);
void init();
void information(std::string& name);
Word printMenu(int x, int y);
Word printPlay(int x, int y);
void printInformation(int x, int y, int hieght, int width, user* User , snake& Snake, int level);
void endGame(bool& _quit_, bool& _Playing_);


#endif // !_MY_UI