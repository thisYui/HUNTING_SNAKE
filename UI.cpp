#include "UI.h"
#include "console.h"
#include <conio.h>
#include <io.h>
#include <fcntl.h>

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

void information(std::string& name)
{

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

void printInformation(int x, int y, int hieght, int width, user* User, snake& Snake, int level)
{

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
