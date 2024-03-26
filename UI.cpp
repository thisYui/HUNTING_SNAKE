#include "UI.h"
#include "console.h"
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <thread>
#include <chrono>

#pragma comment(lib, "winmm.lib")

const char* GAME_TITLE = "HUNGTING SNAKE";

namespace alphabet
{
    void printA(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \ )"; gotoXY(x, y++);
        std::cout << R"(        /::\   \ )"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(    /:::/__\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(   /::::\   \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(  /::::::\   \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"( /:::/\:::\   \:::\___\ )"; gotoXY(x, y++);
        std::cout << R"(/:::/  \:::\  /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(\::/   /\:::\/:::/   /)"; gotoXY(x, y++);
        std::cout << R"( \/___/  \::::::/   /)"; gotoXY(x, y++);
        std::cout << R"(          \::::/   /)"; gotoXY(x, y++);
        std::cout << R"(          /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(         /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(        /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(       /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(       \::/   /)"; gotoXY(x, y++);
        std::cout << R"(        \/___/)"; gotoXY(x, y++);
    }
    void printB(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \ )"; gotoXY(x, y++);
        std::cout << R"(        /::\   \ )"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(    /:::/__\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(   /::::\   \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(  /::::::\   \:::\___\ )"; gotoXY(x, y++);
        std::cout << R"( /:::/\:::\   \:::|   | )"; gotoXY(x, y++);
        std::cout << R"(/:::/__\:::\  /:::|___|)"; gotoXY(x, y++);
        std::cout << R"(\:::\   \:::\/:::/   /)"; gotoXY(x, y++);
        std::cout << R"( \:::\   \::::::/   /)"; gotoXY(x, y++);
        std::cout << R"(  \:::\   \::::/   /)"; gotoXY(x, y++);
        std::cout << R"(   \:::\  /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(    \:::\/:::/   /)"; gotoXY(x, y++);
        std::cout << R"(     \::::::/   /)"; gotoXY(x, y++);
        std::cout << R"(      \::::/   /)"; gotoXY(x, y++);
        std::cout << R"(       \::/   /)"; gotoXY(x, y++);
        std::cout << R"(        \/___/)"; gotoXY(x, y++);
    }
    void printC(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \ )"; gotoXY(x, y++);
        std::cout << R"(        /::\   \ )"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(    /:::/  \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(   /:::/   /\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(  /:::/   /  \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"( /:::/   /    \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(/:::/___/      \:::\___\ )"; gotoXY(x, y++);
        std::cout << R"(\:::\   \       \::/   /)"; gotoXY(x, y++);
        std::cout << R"( \:::\   \  	 \/___/)"; gotoXY(x, y++);
        std::cout << R"(  \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(   \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(    \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(     \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(      \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(       \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(        \:::\___\)"; gotoXY(x, y++);
        std::cout << R"(         \::/   /)"; gotoXY(x, y++);
        std::cout << R"(          \/___/)"; gotoXY(x, y++);
    }
    void printD(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);  std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \ )"; gotoXY(x, y++);
        std::cout << R"(        /::\   \ )"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(    /:::/  \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(   /:::/   /\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(  /:::/   /  \:::\___\ )"; gotoXY(x, y++);
        std::cout << R"( /:::/   /    \:::|   | )"; gotoXY(x, y++);
        std::cout << R"(/:::/   /     /:::|___|)"; gotoXY(x, y++);
        std::cout << R"(\:::\  /     /:::/   /)"; gotoXY(x, y++);
        std::cout << R"( \:::\/     /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(  \:::\    /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(   \:::\  /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(    \:::\/:::/   /)"; gotoXY(x, y++);
        std::cout << R"(     \::::::/   /)"; gotoXY(x, y++);
        std::cout << R"(      \::::/   /)"; gotoXY(x, y++);
        std::cout << R"(       \::/   /)"; gotoXY(x, y++);
        std::cout << R"(        \/___/)"; gotoXY(x, y++);
    }
    void printE(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \ )"; gotoXY(x, y++);
        std::cout << R"(        /::\   \ )"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(    /:::/__\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(   /::::\   \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(  /::::::\   \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"( /:::/\:::\   \:::\___\ )"; gotoXY(x, y++);
        std::cout << R"(/:::/__\:::\   \::/   /)"; gotoXY(x, y++);
        std::cout << R"(\:::\   \:::\   \/___/)"; gotoXY(x, y++);
        std::cout << R"( \:::\   \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(  \:::\   \:::\___\)"; gotoXY(x, y++);
        std::cout << R"(   \:::\   \::/   /)"; gotoXY(x, y++);
        std::cout << R"(    \:::\   \/___/)"; gotoXY(x, y++);
        std::cout << R"(     \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(      \:::\___\)"; gotoXY(x, y++);
        std::cout << R"(       \::/   /)"; gotoXY(x, y++);
        std::cout << R"(        \/___/)"; gotoXY(x, y++);
    }
    void printG(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \ )"; gotoXY(x, y++);
        std::cout << R"(        /::\   \ )"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(    /:::/  \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(   /:::/   /\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(  /:::/   /  \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"( /:::/   /    \:::\___\ )"; gotoXY(x, y++);
        std::cout << R"(/:::/___/   ___\::/   /)"; gotoXY(x, y++);
        std::cout << R"(\:::\   \  /\   \/___/)"; gotoXY(x, y++);
        std::cout << R"( \:::\   \/::\   \)"; gotoXY(x, y++);
        std::cout << R"(  \:::\   \:::\___\)"; gotoXY(x, y++);
        std::cout << R"(   \:::\  /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(    \:::\/:::/   /)"; gotoXY(x, y++);
        std::cout << R"(     \::::::/   /)"; gotoXY(x, y++);
        std::cout << R"(      \::::/   /)"; gotoXY(x, y++);
        std::cout << R"(       \::/   /)"; gotoXY(x, y++);
        std::cout << R"(        \/___/)"; gotoXY(x, y++);
    }
    void printH(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \ )"; gotoXY(x, y++);
        std::cout << R"(        /::\___\ )"; gotoXY(x, y++);
        std::cout << R"(       /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(      /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(     /:::/   /     ____)"; gotoXY(x, y++);
        std::cout << R"(    /:::/___/     /\   \)"; gotoXY(x, y++);
        std::cout << R"(   /::::\   \    /::\___\)"; gotoXY(x, y++);
        std::cout << R"(  /::::::\   \  /:::/   /)"; gotoXY(x, y++);
        std::cout << R"( /:::/\:::\   \/:::/   /)"; gotoXY(x, y++);
        std::cout << R"(/:::/  \:::\  /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(\::/   /\:::\/:::/   /)"; gotoXY(x, y++);
        std::cout << R"( \/___/  \::::::/   /)"; gotoXY(x, y++);
        std::cout << R"(          \::::/   /)"; gotoXY(x, y++);
        std::cout << R"(          /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(         /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(        /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(       /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(       \::/   /)"; gotoXY(x, y++);
        std::cout << R"(        \/___/)"; gotoXY(x, y++);
    }
    void printK(int x, int y)
    {
		gotoXY(x, y++);
		std::cout << R"(          ____)"; gotoXY(x, y++);
		std::cout << R"(         /\   \ )"; gotoXY(x, y++);
		std::cout << R"(        /::\___\ )"; gotoXY(x, y++);
		std::cout << R"(       /:::/   /)"; gotoXY(x, y++);
		std::cout << R"(      /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(     /:::/   / ____)"; gotoXY(x, y++);
		std::cout << R"(    /:::/___/ /\   \)"; gotoXY(x, y++);
		std::cout << R"(   /::::\   \/::\___\)"; gotoXY(x, y++);
		std::cout << R"(  /::::::\__/:::/   /)"; gotoXY(x, y++);
		std::cout << R"( /:::/\::::::::/   /)"; gotoXY(x, y++);
		std::cout << R"(/:::/  \::::::/   /)"; gotoXY(x, y++);
		std::cout << R"(\::/   /|::::/   /)"; gotoXY(x, y++);
		std::cout << R"( \/___/ |:::/   /)"; gotoXY(x, y++);
        std::cout << R"(        |::/   /)"; gotoXY(x, y++);
        std::cout << R"(        |::|   | )"; gotoXY(x, y++);
        std::cout << R"(        |::|   |)"; gotoXY(x, y++);
        std::cout << R"(        |::|   |)"; gotoXY(x, y++);
        std::cout << R"(        |::|   |)"; gotoXY(x, y++);
        std::cout << R"(        \::|   |)"; gotoXY(x, y++);
        std::cout << R"(         \:|   |)"; gotoXY(x, y++);
        std::cout << R"(          \|___|)"; gotoXY(x, y++);
    }
    void printI(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \ )"; gotoXY(x, y++);
        std::cout << R"(        /::\   \ )"; gotoXY(x, y++);
        std::cout << R"(        \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(         \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(          \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(          /::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(         /::::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(  ____  /::::::::\   \ )"; gotoXY(x, y++);
        std::cout << R"( /\   \/:::::/\:::\___\ )"; gotoXY(x, y++);
        std::cout << R"(/::\  /:::::/  \::/   /)"; gotoXY(x, y++);
        std::cout << R"(\:::\/:::::/   /\/___/)"; gotoXY(x, y++);
        std::cout << R"( \::::::::/   /)"; gotoXY(x, y++);
        std::cout << R"(  \::::::/   /)"; gotoXY(x, y++);
        std::cout << R"(   \::::/___/)"; gotoXY(x, y++);
        std::cout << R"(    \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(     \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(      \:::\___\)"; gotoXY(x, y++);
        std::cout << R"(       \::/   /)"; gotoXY(x, y++);
        std::cout << R"(        \/___/)"; gotoXY(x, y++);
    }
    void printM(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \ )"; gotoXY(x, y++);
        std::cout << R"(        /::\   \ )"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(    /:::/  \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(   /:::/   /::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(  /:::/   /::::::\   \ )"; gotoXY(x, y++);
        std::cout << R"( /:::/   /:::/\:::\___\ )"; gotoXY(x, y++);
        std::cout << R"(/:::/   /:::/  \:::|   |)"; gotoXY(x, y++);
        std::cout << R"(\::/   /:::/   /:::|___|)"; gotoXY(x, y++);
        std::cout << R"( \/___/:::/   /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(     /:::/   /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(    /:::/   /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(    \::/   /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(     \/___/:::/   /)"; gotoXY(x, y++);
        std::cout << R"(         /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(         \::/   /)"; gotoXY(x, y++);
        std::cout << R"(          \/___/)"; gotoXY(x, y++);
    }
    void printN(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \ )"; gotoXY(x, y++);
        std::cout << R"(        /::\   \ )"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(    /:::/  \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(   /:::/   /\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(  /:::/   /  \:::\___\ )"; gotoXY(x, y++);
        std::cout << R"( /:::/   /    |:::|   | )"; gotoXY(x, y++);
        std::cout << R"(/:::/   /     |:::|___|)"; gotoXY(x, y++);
        std::cout << R"(\::/   /      /:::/   /)"; gotoXY(x, y++);
        std::cout << R"( \/___/      /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(            /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(           /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(          /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(         /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(        /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(        \::/   /)"; gotoXY(x, y++);
        std::cout << R"(         \/___/)"; gotoXY(x, y++);
    }
    void printO(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"()"; gotoXY(x, y++);
        std::cout << R"(         ______ )"; gotoXY(x, y++);
        std::cout << R"(        /::\   \ )"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(    /:::/__\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(   /:::/   /\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(  /:::/   /  \:::\___\ )"; gotoXY(x, y++);
        std::cout << R"( /:::/   /    \:::|   | )"; gotoXY(x, y++);
        std::cout << R"(/:::/   /     /:::|___|)"; gotoXY(x, y++);
        std::cout << R"(\:::\  /     /:::/   /)"; gotoXY(x, y++);
        std::cout << R"( \:::\/     /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(  \:::\    /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(   \:::\  /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(    \:::\/:::/   /)"; gotoXY(x, y++);
        std::cout << R"(     \::::::/   /)"; gotoXY(x, y++);
        std::cout << R"(      \::::/   /)"; gotoXY(x, y++);
        std::cout << R"(       \__/___/)"; gotoXY(x, y++);

    }
    void printP(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \ )"; gotoXY(x, y++);
        std::cout << R"(        /::\   \ )"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(    /:::/__\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(   /::::\   \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(  /::::::\   \:::\___\ )"; gotoXY(x, y++);
        std::cout << R"( /:::/\:::\   \:::|   | )"; gotoXY(x, y++);
        std::cout << R"(/:::/__\:::\  /:::|___|)"; gotoXY(x, y++);
        std::cout << R"(\::/   /\:::\/:::/   /)"; gotoXY(x, y++);
        std::cout << R"( \/___/  \::::::/   /)"; gotoXY(x, y++);
        std::cout << R"(          \::::/___/)"; gotoXY(x, y++);
        std::cout << R"(           ---- )"; gotoXY(x, y++);

    }
    void printU(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \ )"; gotoXY(x, y++);
        std::cout << R"(        /::\___\ )"; gotoXY(x, y++);
        std::cout << R"(       /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(      /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(     /:::/   / )"; gotoXY(x, y++);
        std::cout << R"(    /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(   /:::/   /     ____ )"; gotoXY(x, y++);
        std::cout << R"(  /:::/   /     /\   \)"; gotoXY(x, y++);
        std::cout << R"( /:::/   /     /::\___\ )"; gotoXY(x, y++);
        std::cout << R"(/:::/___/     /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(\:::\   \    /:::/   /)"; gotoXY(x, y++);
        std::cout << R"( \:::\   \  /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(  \:::\   \/:::/   /)"; gotoXY(x, y++);
        std::cout << R"(   \:::\  /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(    \:::\/:::/   /)"; gotoXY(x, y++);
        std::cout << R"(     \::::::/   /)"; gotoXY(x, y++);
        std::cout << R"(      \::::/   /)"; gotoXY(x, y++);
        std::cout << R"(       \::/   /)"; gotoXY(x, y++);
        std::cout << R"(        \/___/)"; gotoXY(x, y++);
    }
    void printV(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \ )"; gotoXY(x, y++);
        std::cout << R"(        /::\___\ )"; gotoXY(x, y++);
        std::cout << R"(       /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(      /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(     /:::/   / )"; gotoXY(x, y++);
        std::cout << R"(    /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(   /:::/   /     ____ )"; gotoXY(x, y++);
        std::cout << R"(  /:::/___/     /\   \)"; gotoXY(x, y++);
        std::cout << R"( |:::|   |     /::\___\ )"; gotoXY(x, y++);
        std::cout << R"( |:::|   |    /:::/   /)"; gotoXY(x, y++);
        std::cout << R"( |:::|___|   /:::/   /)"; gotoXY(x, y++);
        std::cout << R"( \:::\   \  /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(  \:::\   \/:::/   /)"; gotoXY(x, y++);
        std::cout << R"(   \:::\__/:::/   /)"; gotoXY(x, y++);
        std::cout << R"(    \::::::::/   /)"; gotoXY(x, y++);
        std::cout << R"(     \::::::/___/)"; gotoXY(x, y++);
    }
    void printW(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \ )"; gotoXY(x, y++);
        std::cout << R"(        /::\___\ )"; gotoXY(x, y++);
        std::cout << R"(       /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(      /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(     /:::/   / ___)"; gotoXY(x, y++);
        std::cout << R"(    /:::/   //\   \)"; gotoXY(x, y++);
        std::cout << R"(   /:::/   //::\___\ )"; gotoXY(x, y++);
        std::cout << R"(  /:::/   //:::/   /  )"; gotoXY(x, y++);
        std::cout << R"( /:::/   //:::/   /)"; gotoXY(x, y++);
        std::cout << R"(|:::|   //:::/   / ___)"; gotoXY(x, y++);
        std::cout << R"(|:::|__|/:::/   / /\   \)"; gotoXY(x, y++);
        std::cout << R"(\:::\  /:::/   / /::\___\)"; gotoXY(x, y++);
        std::cout << R"( \:::\/:::/   / /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(  \::::::/   / /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(   \::::/   / /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(    \:::\  / /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(     \:::\/ /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(      \:::\/:::/   /)"; gotoXY(x, y++);
        std::cout << R"(       \::::::/___/)"; gotoXY(x, y++);
    }
    void printR(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \ )"; gotoXY(x, y++);
        std::cout << R"(        /::\   \ )"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \)"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \)"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(    /:::/__\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(   /::::\   \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(  /::::::\   \:::\   \)"; gotoXY(x, y++);
        std::cout << R"( /:::/\:::\   \:::\___\)"; gotoXY(x, y++);
        std::cout << R"(/:::/  \:::\   \:::|   |)"; gotoXY(x, y++);
        std::cout << R"(\::/   /|:::\  /:::|___|)"; gotoXY(x, y++);
        std::cout << R"( \/___/ |::::\/:::/   /)"; gotoXY(x, y++);
        std::cout << R"(        |::::::::/   /)"; gotoXY(x, y++);
        std::cout << R"(        |::|\:::/   /)"; gotoXY(x, y++);
        std::cout << R"(        |::| \_/___/)"; gotoXY(x, y++);
        std::cout << R"(        |::|   |)"; gotoXY(x, y++);
        std::cout << R"(        |::|   |)"; gotoXY(x, y++);
        std::cout << R"(        \::|   |)"; gotoXY(x, y++);
        std::cout << R"(         \:|   |)"; gotoXY(x, y++);
        std::cout << R"(          \|___|)"; gotoXY(x, y++);
    }
    void printS(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \ )"; gotoXY(x, y++);
        std::cout << R"(        /::\   \ )"; gotoXY(x, y++);
        std::cout << R"(        \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(         \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(     _____\:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(    /::\   \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(   /::::\   \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(  /::::::\   \:::\___\ )"; gotoXY(x, y++);
        std::cout << R"( /:::/\:::\   \:::|   | )"; gotoXY(x, y++);
        std::cout << R"( |::/__\:::\  /:::|___|)"; gotoXY(x, y++);
        std::cout << R"( |::\   \:::\/:::/   /)"; gotoXY(x, y++);
        std::cout << R"( \:::\   \::::::/   /)"; gotoXY(x, y++);
        std::cout << R"(  \:::\   \::::/___/)"; gotoXY(x, y++);
        std::cout << R"(   \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(    \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(     \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(      \:::\___\)"; gotoXY(x, y++);
        std::cout << R"(       \::/   /)"; gotoXY(x, y++);
        std::cout << R"(        \/___/)"; gotoXY(x, y++);
    }
    void printT(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \ )"; gotoXY(x, y++);
        std::cout << R"(        /::\   \ )"; gotoXY(x, y++);
        std::cout << R"(        \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(         \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(          \:::\   \ )"; gotoXY(x, y++);
        std::cout << R"(          /::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(         /::::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(        /::::::::\   \ )"; gotoXY(x, y++);
        std::cout << R"(       /:::::/\:::\___\ )"; gotoXY(x, y++);
        std::cout << R"(      /:::::/  \::/   /)"; gotoXY(x, y++);
        std::cout << R"(     /:::::/   /\/___/)"; gotoXY(x, y++);
        std::cout << R"(    /:::::/   /)"; gotoXY(x, y++);
        std::cout << R"(   /:::::/   /)"; gotoXY(x, y++);
        std::cout << R"(   \::::/   /)"; gotoXY(x, y++);
        std::cout << R"(    \::/   /)"; gotoXY(x, y++);
        std::cout << R"(     \/___/)"; gotoXY(x, y++);

    }
}

void soundTrack(bool& status)
{
    const char* filePath = "C:/Users/DELL/Downloads/musix.wav";
    PlaySoundA(filePath, NULL, SND_FILENAME | SND_ASYNC);
}
void soudPlay(bool& status)
{

}
void fillFullScreen(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    int consoleWidth = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
    int consoleHeight = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
    
    setBackgroudAndText(color);
    for (int i = 0; i < consoleHeight; i++)
    {
        for (int j = 0; j < consoleWidth; j++)
        {
			std::cout << " ";
		}
	}
}

void init()
{
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);// toàn màng hình
    disableResizeWindow();// vô hiệu hóa nút resize console
    //disableCtrButton(false, false, false);// vô hiệu hóa nút close, minimize, maximize
    showScrollbar(FALSE);//ẩn thanh cuộn
    noneCursorType();//ẩn con trỏ
    fillFullScreen(0xf0);
    setBackgroudAndText(0xf0);
    disableSelection();// vô hiệu hóa chọn text
    
    int n = 24;
    int y = 4;
    int z = 5;
    /*alphabet::printG(6 * (n - z) + z, y);
    alphabet::printN(5 * (n - z) + z, y);
    alphabet::printI(4 * (n - z) + z, y);
    alphabet::printT(3 * (n - z) + z, y);
    alphabet::printN(2 * (n - z) + z, y);
    alphabet::printU(n, y);
    alphabet::printH(5, y);*/
    alphabet::printG(z, y);
    alphabet::printA(n + z, y);
    alphabet::printM(2 * n + z, y);
    alphabet::printE(3 * n  + z, y);



    gotoXY(50, 25);
    std::cout << "Tap space to start game";
    system("pause");
    system("cls");
    setFontSize(10, 10);
}

void inforName(user*& player, int x, int y)
{
    gotoXY(x, y++);
    int n = 24;
    int a = 4;
    int z = 5;
    alphabet::printN(z, a);
    alphabet::printA(n + z, a);
    alphabet::printM(2 * n + z, a);
    alphabet::printE(3 * n + z, a);

    gotoXY(x + 40, y + 25);
    std::cout << "Enter your name: ";
    std::cin >> player->name;
    std::cin.ignore();
    system("cls");
}
Word printMenu(int x, int y)
{
    int n = 24;
    int m = 4;
    int z = 5;
    alphabet::printM(z, m);
    alphabet::printE(n + z, m);
    alphabet::printN(2 * n + z, m);
    alphabet::printU(3 * n + z, m);

    Word choose = Word::StarGame;
    while (true)
    {
        for (Word i = StarGame; int(i) <= 5; i++)
        {
            gotoXY(x, y + int(i));
            if (i == choose)
            {
			    setBackgroudAndText(0x0f);
                std::cout << i;
                setBackgroudAndText(0xf0);
		    }
            else std::cout << i;
        }
        if (_kbhit())
        {
			char key = _getch();
			if (key == 72 && int(choose) > 0) choose = Word(int(choose) - 1);
			//up
            if (key == 80 && int(choose) <= 5) choose = Word(int(choose) + 1);
			//down
            if (key == 13) return choose;
            //enter
            if (key == 27 || key == 'q') return Word::Exit;
            //esc
            continue;
		}
    }
}
Word printPlay(int x, int y)
{
    int n = 24;
    int m = 4;
    int z = 5;
    alphabet::printS(z, m);
    alphabet::printT(n + z, m);
    alphabet::printA(2 * n + z, m);
    alphabet::printR(3 * n + z, m);
    alphabet::printT(4 * n + z, m);

    Word choose = Word::StarGame;
    while (true)
    {
        for (Word i = NewGame; int(i) <= 7; i++)
        {
            gotoXY(x, y + int(i));
            if (i == choose)
            {
                setBackgroudAndText(0x0f);
                std::cout << i;
                setBackgroudAndText(0xf0);
            }
            else std::cout << i;
        }
        if (_kbhit())
        {
            char key = _getch();
            if (key == 72 && int(choose) > 5) choose = Word(int(choose) - 1);
            //up
            if (key == 80 && int(choose) <= 7) choose = Word(int(choose) + 1);
            //down
            if (key == 13) return choose;
            //enter
            if (key == 27 || key == 'q') return Word::Exit;
            //esc
            continue;
        }
    }
}

void setMusic(bool& statusTrack, bool& statusSound, int x, int y)
{
}

void printRecord(user* listUser, int countUser, int x, int y)
{
    gotoXY(x, y++);
    int n = 24;
	int m = 4;
	int z = 5;
	alphabet::printR(z, m);
	alphabet::printE(n + z, m);
	alphabet::printC(2 * n + z, m);
	alphabet::printO(3 * n + z, m);
	alphabet::printR(4 * n + z, m);
	alphabet::printD(5 * n + z, m);

	x += 5; y += 20;
    for (int i = 0; i < countUser; i++)
    {
		gotoXY(x, y++);
		std::cout << i + 1 << "\t" << listUser[i].name 
            << "\t" << listUser[i].score;
	}
	std::cout << "Press space to continue";

    while (true)
    {
        if (_kbhit())
        {
			char key = _getch();
			if (key == 32) return;
		}
	}
}
void printAboutUs(int x, int y)
{
    gotoXY(x, y++);
    int n = 24;
	int m = 4;
	int z = 5;
	alphabet::printU(z, m);
    alphabet::printS(n + z, m);

    int olMode = _setmode(_fileno(stdout), _O_U16TEXT);

    x += 60; y += 5;
    gotoXY(x, y++);
    std::wcout << L"Đồ án môn học: Kĩ thuật lập trình"; gotoXY(x++, y++);
    std::wcout << L"Nhóm thực hiện: Nhóm 15"; gotoXY(x, y++);
    std::wcout << L"Nguyễn Quang Duy - MSSV: 23120245"; gotoXY(x, y++);
    std::wcout << L"Lưu Trọng Hiếu - MSSV: 23120258"; gotoXY(x, y++);
    std::wcout << L"Văn Đình Hiếu - MSSV: 23120260"; gotoXY(x, y++);
    std::wcout << L"Nguyễn Văn Chiến - MSSV: 23120219"; gotoXY(x, y++);
    std::wcout << L"Võ Việt Anh - MSSV: 23120213";gotoXY(x, y++);
    std::wcout << L"Press space to continue";

    _setmode(_fileno(stdout), olMode);

    while (true)
    {
        if (_kbhit())
        {
            char key = _getch();
            if (key == 32) return;
        }
    }
}
void printPause(int x, int y)
{
    int n = 24;
    int m = 4;
    int z = 5;
    alphabet::printP(z, m);
    alphabet::printA(n + z, m);
    alphabet::printU(2 * n + z, m);
    alphabet::printS(3 * n + z, m);
    alphabet::printE(4 * n + z, m);

    std::cout << "Press space to continue";
    while (true)
    {
        if (_kbhit())
        {
            char key = _getch();
            if (key == 32) return;
        }
    }
}
void printGameOver(int x, int y)
{
    int n = 24;
    int m = 4;
    int z = 5;
    alphabet::printG(z, m);
    alphabet::printA(n + z, m);
    alphabet::printM(2 * n + z, m);
    alphabet::printE(3 * n + z, m);
    m += 20;
    alphabet::printO(z, m);
    alphabet::printV(n + z, m);
    alphabet::printE(2 * n + z, m);
    alphabet::printR(3 * n + z, m);

    while (true)
    {
        if (_kbhit())
        {
            char key = _getch();
            if (key == 32) return;
        }
    }
}
void printWin(int x, int y)
{
    int n = 24;
	int m = 4;
	int z = 5;
	alphabet::printW(z, m);
	alphabet::printI(n + z, m);
	alphabet::printN(2 * n + z, m);

    while (true)
    {
        if (_kbhit())
        {
            char key = _getch();
            if (key == 32) return;
        }
    }
}
bool printContinue(int x, int y)
{
    gotoXY(x, y++);
    int n = 24;
	int m = 4;
	int z = 5;
	alphabet::printC(z, m);
	alphabet::printO(n + z, m);
	alphabet::printN(2 * n + z, m);
	alphabet::printT(3 * n + z, m);
	alphabet::printI(4 * n + z, m);
	alphabet::printN(5 * n + z, m);
	alphabet::printU(6 * n + z, m);
	alphabet::printE(7 * n + z, m);

    gotoXY(x + 20, y + 20);
    std::cout << "Do you want to play continue? (y/n)";
    while (true)
    {
        if (_kbhit())
        {
			char key = _getch();
			if (key == 'y') return true;
			if (key == 'n') return false;
		}
	}
}
bool printResult(user* User, int level, int x, int y, bool win)
{
    gotoXY(x, y++);
	std::cout << "Name: " << User->name;
	gotoXY(x, y++);
	std::cout << "Score: " << User->score;
	gotoXY(x, y++);
    std::cout << "Time: " << User->timePlay;
	gotoXY(x, y++);
	std::cout << "Level: " << level;
	gotoXY(x, y++);
    
    if (!win) return false;

    std::cout << "Do you want to save? (y/n)";
    while (true)
    {
		if (_kbhit())
		{ 
            char key = _getch();
            if (key == 'y')
            {
                return true;
			}
            if (key == 'n')
            {
				return false;
			}
        }
    }
}
void printInformation(int x, int y, bool& _Playing_, user* User, snake& Snake)
{
    gotoXY(x, y + 6);
    std::cout << "Press 'q' to exit";
    gotoXY(x, y + 7);
    std::cout << "Press 'p' to pause";
    gotoXY(x, y + 8);
    std::cout << "Press 'o' to turn off music";
    while (_Playing_)
    {
        User->timePlay = int(clock() / CLOCKS_PER_SEC);
        gotoXY(x, y + 1);
        std::cout << "Name: " << User->name;
        gotoXY(x, y + 2);
        std::cout << "Score: " << User->score;
        gotoXY(x, y + 3);
        std::cout << "Time: " << User->timePlay;
        gotoXY(x, y + 4);
        std::cout << "Length: " << Snake.length;
        gotoXY(x, y + 5);
        std::cout << "Speed: " << Snake.speed;
        
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}


void endGame(bool &_quit_, bool &_Playing_)
{
    if (_kbhit()) 
    {
        char key = _getch();
        if (key == 'q')
        {
            _quit_ = true;
            _Playing_ = false;
        }
    }
}
