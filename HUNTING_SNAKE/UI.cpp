#include "UI.h"
#include "console.h"

#pragma comment(lib, "winmm.lib")

const char* GAME_TITLE = "HUNTING SNAKE";
const char* SOUND_TRACK = "cruising-down-8bit-lane-159615.wav";
const char* SOUND_PLAY = "sinnesloschen-beam-117362.wav";
std::mutex mtx;
static const char animation[2][7][5] = {
    { ">   ", " >  ", "  > ", "   >", "  > ", " >  ", ">   "},
    { "   <", "  < ", " <  ", "<   ", " <  ", "  < ", "   <"} };

namespace alphabet
{
    void printA(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \)"; gotoXY(x, y++);
        std::cout << R"(        /::\   \)"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \)"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \)"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(    /:::/__\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(   /::::\   \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(  /::::::\   \:::\   \)"; gotoXY(x, y++);
        std::cout << R"( /:::/\:::\   \:::\___\)"; gotoXY(x, y++);
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
        std::cout << R"(         /\   \)"; gotoXY(x, y++);
        std::cout << R"(        /::\   \)"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \)"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \)"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(    /:::/__\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(   /::::\   \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(  /::::::\   \:::\___\)"; gotoXY(x, y++);
        std::cout << R"( /:::/\:::\   \:::|   |)"; gotoXY(x, y++);
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
        std::cout << R"(         /\   \)"; gotoXY(x, y++);
        std::cout << R"(        /::\   \)"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \)"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \)"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(    /:::/  \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(   /:::/   /\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(  /:::/   /  \:::\   \)"; gotoXY(x, y++);
        std::cout << R"( /:::/   /    \:::\___\)"; gotoXY(x, y++);
        std::cout << R"(/:::/___/      \::/   /)"; gotoXY(x, y++);
        std::cout << R"(\:::\   \       \/___/)"; gotoXY(x, y++);
        std::cout << R"( \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(  \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(   \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(    \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(     \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(      \:::\___\)"; gotoXY(x, y++);
        std::cout << R"(       \::/   /)"; gotoXY(x, y++);
        std::cout << R"(        \/___/)"; gotoXY(x, y++);
    }
    void printD(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \)"; gotoXY(x, y++);
        std::cout << R"(        /::\   \)"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \)"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \)"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(    /:::/  \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(   /:::/   /\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(  /:::/   /  \:::\___\)"; gotoXY(x, y++);
        std::cout << R"( /:::/   /    \:::|   |)"; gotoXY(x, y++);
        std::cout << R"(/:::/   /     /:::|___|)"; gotoXY(x, y++);
        std::cout << R"(\:::\  /     /:::/   /)"; gotoXY(x, y++);
        std::cout << R"( \:::\/     /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(  \:::\    /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(   \:::\  /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(    \:::\/:::/   /)"; gotoXY(x, y++);
        std::cout << R"(     \::::::/   /)"; gotoXY(x, y++);
        std::cout << R"(      \::::/   /)"; gotoXY(x, y++);
        std::cout << R"(       \::/___/)"; gotoXY(x, y++);
    }
    void printE(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \)"; gotoXY(x, y++);
        std::cout << R"(        /::\   \)"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \)"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \)"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(    /:::/__\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(   /::::\   \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(  /::::::\   \:::\   \)"; gotoXY(x, y++);
        std::cout << R"( /:::/\:::\   \:::\___\)"; gotoXY(x, y++);
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
        std::cout << R"(         /\   \)"; gotoXY(x, y++);
        std::cout << R"(        /::\   \)"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \)"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \)"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(    /:::/  \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(   /:::/   /\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(  /:::/   /  \:::\   \)"; gotoXY(x, y++);
        std::cout << R"( /:::/   /    \:::\___\)"; gotoXY(x, y++);
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
        std::cout << R"(         /\   \)"; gotoXY(x, y++);
        std::cout << R"(        /::\___\)"; gotoXY(x, y++);
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
        std::cout << R"(         /\   \)"; gotoXY(x, y++);
        std::cout << R"(        /::\___\)"; gotoXY(x, y++);
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
        std::cout << R"(        |::|   |)"; gotoXY(x, y++);
        std::cout << R"(        |::|   |)"; gotoXY(x, y++);
        std::cout << R"(        |::|   |)"; gotoXY(x, y++);
        std::cout << R"(        |::|   |)"; gotoXY(x, y++);
        std::cout << R"(        \::|   |)"; gotoXY(x, y++);
        std::cout << R"(         \:|   |)"; gotoXY(x, y++);
        std::cout << R"(          \|___|)"; gotoXY(x, y++);
    }
    void printL(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \)"; gotoXY(x, y++);
        std::cout << R"(        /::\___\)"; gotoXY(x, y++);
        std::cout << R"(       /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(      /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(     /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(    /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(   /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(  /:::/   /)"; gotoXY(x, y++);
        std::cout << R"( /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(/:::/___/)"; gotoXY(x, y++);
        std::cout << R"(\:::\   \)"; gotoXY(x, y++);
        std::cout << R"( \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(  \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(   \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(    \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(     \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(      \:::\___\)"; gotoXY(x, y++);
        std::cout << R"(       \::/   /)"; gotoXY(x, y++);
        std::cout << R"(        \/___/)"; gotoXY(x, y++);
    }
    void printI(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \)"; gotoXY(x, y++);
        std::cout << R"(        /::\   \)"; gotoXY(x, y++);
        std::cout << R"(        \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(         \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(          \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(          /::::\   \)"; gotoXY(x, y++);
        std::cout << R"(         /::::::\   \)"; gotoXY(x, y++);
        std::cout << R"(  ____  /::::::::\   \)"; gotoXY(x, y++);
        std::cout << R"( /\   \/:::::/\:::\___\)"; gotoXY(x, y++);
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
        std::cout << R"(         /\   \)"; gotoXY(x, y++);
        std::cout << R"(        /::\   \)"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \)"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \)"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(    /:::/  \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(   /:::/   /::::\   \)"; gotoXY(x, y++);
        std::cout << R"(  /:::/   /::::::\   \)"; gotoXY(x, y++);
        std::cout << R"( /:::/   /:::/\:::\___\)"; gotoXY(x, y++);
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
        std::cout << R"(         /\   \)"; gotoXY(x, y++);
        std::cout << R"(        /::\   \)"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \)"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \)"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(    /:::/  \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(   /:::/   /\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(  /:::/   /  \:::\___\)"; gotoXY(x, y++);
        std::cout << R"( /:::/   /    |:::|   |)"; gotoXY(x, y++);
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
        std::cout << R"(        /::\   \)"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \)"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \)"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(    /:::/__\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(   /:::/   /\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(  /:::/   /  \:::\___\)"; gotoXY(x, y++);
        std::cout << R"( /:::/   /    \:::|   |)"; gotoXY(x, y++);
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
        std::cout << R"(         /\   \)"; gotoXY(x, y++);
        std::cout << R"(        /::\   \)"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \)"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \)"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(    /:::/__\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(   /::::\   \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(  /::::::\   \:::\___\)"; gotoXY(x, y++);
        std::cout << R"( /:::/\:::\   \:::|   |)"; gotoXY(x, y++);
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
        std::cout << R"(         /\   \)"; gotoXY(x, y++);
        std::cout << R"(        /::\___\)"; gotoXY(x, y++);
        std::cout << R"(       /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(      /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(     /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(    /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(   /:::/   /     ____ )"; gotoXY(x, y++);
        std::cout << R"(  /:::/   /     /\   \)"; gotoXY(x, y++);
        std::cout << R"( /:::/   /     /::\___\)"; gotoXY(x, y++);
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
        std::cout << R"(         /\   \)"; gotoXY(x, y++);
        std::cout << R"(        /::\___\)"; gotoXY(x, y++);
        std::cout << R"(       /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(      /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(     /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(    /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(   /:::/   /     ____ )"; gotoXY(x, y++);
        std::cout << R"(  /:::/___/     /\   \)"; gotoXY(x, y++);
        std::cout << R"( |:::|   |     /::\___\)"; gotoXY(x, y++);
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
        std::cout << R"(         /\   \)"; gotoXY(x, y++);
        std::cout << R"(        /::\___\)"; gotoXY(x, y++);
        std::cout << R"(       /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(      /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(     /:::/   / ___)"; gotoXY(x, y++);
        std::cout << R"(    /:::/   //\   \)"; gotoXY(x, y++);
        std::cout << R"(   /:::/   //::\___\)"; gotoXY(x, y++);
        std::cout << R"(  /:::/   //:::/   /  )"; gotoXY(x, y++);
        std::cout << R"( /:::/   //:::/   /)"; gotoXY(x, y++);
        std::cout << R"(|:::|   //:::/   / ___)"; gotoXY(x, y++);
        std::cout << R"(|:::|__|/:::/   / /\   \)"; gotoXY(x, y++);
        std::cout << R"(\:::\  /:::/   / /::\___\)"; gotoXY(x, y++);
        std::cout << R"( \:::\/:::/   / /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(  \::::::/   / /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(   \::::/___/ /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(    \:::\   \/:::/   /)"; gotoXY(x, y++);
        std::cout << R"(     \:::\  /:::/   /)"; gotoXY(x, y++);
        std::cout << R"(      \:::\/:::/   /)"; gotoXY(x, y++);
        std::cout << R"(       \::::::/___/)"; gotoXY(x, y++);
    }
    void printR(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \)"; gotoXY(x, y++);
        std::cout << R"(        /::\   \)"; gotoXY(x, y++);
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
        std::cout << R"(        \::|   |)"; gotoXY(x, y++);
        std::cout << R"(         \:|   |)"; gotoXY(x, y++);
        std::cout << R"(          \|___|)"; gotoXY(x, y++);
    }
    void printS(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \)"; gotoXY(x, y++);
        std::cout << R"(        /::\   \)"; gotoXY(x, y++);
        std::cout << R"(       /::::\   \)"; gotoXY(x, y++);
        std::cout << R"(      /::::::\   \)"; gotoXY(x, y++);
        std::cout << R"(     /:::/\:::\   \)"; gotoXY(x, y++);
        std::cout << R"(    |:::|  \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(    |:::|   \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(  ___\:::\   \:::\   \)"; gotoXY(x, y++);
        std::cout << R"( /\   \:::\   \:::\___\)"; gotoXY(x, y++);
        std::cout << R"(/::\   \:::\   \::/   /)"; gotoXY(x, y++);
        std::cout << R"(\:::\   \:::\   \/___/)"; gotoXY(x, y++);
        std::cout << R"( \:::\   \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(  \:::\   \:::\___\)"; gotoXY(x, y++);
        std::cout << R"(   \:::\   |:::|   |)"; gotoXY(x, y++);
        std::cout << R"(    \:::\  |:::|___|)"; gotoXY(x, y++);
        std::cout << R"(     \:::\/:::/   /)"; gotoXY(x, y++);
        std::cout << R"(      \::::::/   /)"; gotoXY(x, y++);
        std::cout << R"(       \::::/   /)"; gotoXY(x, y++);
        std::cout << R"(        \__/___/)"; gotoXY(x, y++);
    }
    void printT(int x, int y)
    {
        gotoXY(x, y++);
        std::cout << R"(          ____)"; gotoXY(x, y++);
        std::cout << R"(         /\   \)"; gotoXY(x, y++);
        std::cout << R"(        /::\   \)"; gotoXY(x, y++);
        std::cout << R"(        \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(         \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(          \:::\   \)"; gotoXY(x, y++);
        std::cout << R"(          /::::\   \)"; gotoXY(x, y++);
        std::cout << R"(         /::::::\   \)"; gotoXY(x, y++);
        std::cout << R"(        /::::::::\   \)"; gotoXY(x, y++);
        std::cout << R"(       /:::::/\:::\___\)"; gotoXY(x, y++);
        std::cout << R"(      /:::::/  \::/   /)"; gotoXY(x, y++);
        std::cout << R"(     /:::::/   /\/___/)"; gotoXY(x, y++);
        std::cout << R"(    /:::::/   /)"; gotoXY(x, y++);
        std::cout << R"(   /:::::/   /)"; gotoXY(x, y++);
        std::cout << R"(   \::::/   /)"; gotoXY(x, y++);
        std::cout << R"(    \::/   /)"; gotoXY(x, y++);
        std::cout << R"(     \/___/)"; gotoXY(x, y++);

    }
}

void playMusix(const char* path, bool status)
{
    if (status)
    {
        PlaySoundA(path, NULL, SND_ASYNC | SND_LOOP);
    }
    else
    {
        PlaySoundA(NULL, NULL, SND_ASYNC);
    }
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
char init()
{
    //ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);// toàn màng hình
    disableResizeWindow();// vô hiệu hóa nút resipe console
    disableCtrButton(false, true, true);// vô hiệu hóa nút close, minimipe, maximipe
    showScrollbar(FALSE);//ẩn thanh cuộn
    noneCursorType(false);//ẩn con trỏ
    fillFullScreen(0xf0);//tô màu màn hình
    setBackgroudAndText(0xf0);//tô màu chữ
    disableTextSelection();// vô hiệu hóa chọn text
    disableConsoleDragging();// vô hiệu hóa kéo thả console
    setConsoleTitle(GAME_TITLE);//dặt tên cho console

    int n = 20;
    int y = 3;
    int p = 10;
    setBackgroudAndText(0xfc);
    alphabet::printT(4 * n + p - 3, y);
    alphabet::printR(3 * n + p, y);
    alphabet::printA(2 * n + p, y);
    alphabet::printT(n + p, y);
    alphabet::printS(p, y);
    setBackgroudAndText(0xf0);

    int ind = 0;
    while (true)
    {
        gotoXY(40, 27);
        std::cout << animation[0][ind] << " Tap space or enter to start game " << animation[1][ind];
        if (++ind == 7) ind = 0;
        if (_kbhit())
        {
            char key = _getch();
            if (key == 32)
            {
                system("cls");
                return key;
            }
            if (key == 13)
            {
                system("cls");
                return key;
            }
            if (key == 'q')
            {
                system("cls");
                return key;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void inforName(user*& player)
{
    system("cls");
    int n = 24;
    int a = 3;
    int p = 10;
    setBackgroudAndText(0xfc);
    alphabet::printN(p, a);
    alphabet::printA(n + p, a);
    alphabet::printM(2 * n + p, a);
    alphabet::printE(3 * n + p, a);
    setBackgroudAndText(0xf0);

    noneCursorType(true);
    do
    {
        gotoXY(30, a + 23);
        std::cout << "Enter your name(max 15 characters): ";
        getline(std::cin, player->name);

        if (player->name.size() > 15)
        {
            gotoXY(30, a + 22);
            std::cout << "---Name is too long. Please enter again!---";
            gotoXY(66, a + 23);
            std::cout << "                                                        ";
            continue;
        }
        break;
    } while (true);
    noneCursorType(false);
    system("cls");
}
Word printMenu()
{
    system("cls");
    int n = 22;
    int m = 1;
    int p = 15;
    setBackgroudAndText(0xfc);
    alphabet::printU(3 * n + p, m);
    alphabet::printN(2 * n + p, m);
    alphabet::printE(n + p, m);
    alphabet::printM(p, m);
    setBackgroudAndText(0xf0);

    int x = 50, y = 22;
    int ind = 0;
    Word choose = Word::StartGame;
    while (true)
    {
        for (int i = 1; i <= 5; i++)
        {
            gotoXY(x - 4, y + i);
            if (i == choose)
            {
                ind = 0;
                setBackgroudAndText(0xfc);
                std::cout << animation[0][ind] << Word(i) << animation[1][ind];
                setBackgroudAndText(0xf0);
            }
            else
            {
                std::cout << "    " << Word(i) << "    ";
            }
        }
        while (true)
        {
            gotoXY(x - 4, y + choose);
            setBackgroudAndText(0xfc);
            std::cout << animation[0][ind]
                << Word(choose) << animation[1][ind];
            setBackgroudAndText(0xf0);
            if (++ind == 7) ind = 0;

            if (_kbhit())
            {
                char key = _getch();
                if (key == 72 && int(choose) > 0)
                {
                    choose--;
                    break;
                }
                //up
                if (key == 80 && int(choose) <= 5)
                {
                    choose++;
                    break;
                }
                //down
                if (key == 13)
                {
                    system("cls");
                    return choose;
                }
                //enter
                if (key == 27 || key == 'q')
                {
                    system("cls");
                    return Word::Exit;
                }
                //esc
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
    }
}
Word printPlay()
{
    system("cls");
    int n = 22;
    int m = 1;
    int p = 5;
    setBackgroudAndText(0xfc);
    alphabet::printT(4 * n + p - 3, m);
    alphabet::printR(3 * n + p, m);
    alphabet::printA(2 * n + p, m);
    alphabet::printT(n + p, m);
    alphabet::printS(p + 4, m);
    setBackgroudAndText(0xf0);

    int x = 50, y = 18;
    int ind = 0;
    Word choose = Word::NewGame;
    while (true)
    {
        for (int i = 6; i <= 7; i++)
        {
            gotoXY(x - 1, y + int(i));
            if (i == choose)
            {
                ind = 0;
                setBackgroudAndText(0xfc);
                std::cout << animation[0][ind] << Word(i) << animation[1][ind];
                setBackgroudAndText(0xf0);
            }
            else
            {
                std::cout << "    " << Word(i) << "    ";
            }
        }

        while (true)
        {
            gotoXY(x - 1, y + choose);
            setBackgroudAndText(0xfc);
            std::cout << animation[0][ind] << Word(choose) << animation[1][ind];
            setBackgroudAndText(0xf0);
            if (++ind == 7) ind = 0;
            if (_kbhit())
            {
                char key = _getch();
                if (key == 72 && int(choose) > 5)
                {
                    choose--;
                    break;
                }
                //up
                if (key == 80 && int(choose) <= 7)
                {
                    choose++;
                    break;
                }
                //down
                if (key == 13)
                {
                    system("cls");
                    return choose;
                }
                //enter
                if (key == 27 || key == 'q')
                {
                    system("cls");
                    return Word::Exit;
                }
                //esc
                continue;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
    }
}
void setMusic(bool& statusTrack, bool& statusPlay, bool& quit, bool& playing)
{
    system("cls");
    int n = 20;
    int m = 2;
    int p = 8;
    setBackgroudAndText(0xfc);

    alphabet::printC(4 * n + p, m);
    alphabet::printI(3 * n + p, m);
    alphabet::printS(2 * n + p, m);
    alphabet::printU(n + p, m);
    alphabet::printM(p, m);

    setBackgroudAndText(0xf0);

    int x = 50, y = 17;
    int ind = 0;
    Word choose = Track;

    gotoXY(x - 15, y + 11);
    std::cout << "Press enter to change, press space to back";

    gotoXY(x - 6, y + 6);
    std::cout << "--- Turn on/off music ---";
    while (true)
    {
        for (int i = 8; i <= 9; i++)
        {
            gotoXY(x - 2, y + int(i));
            if (i == choose)
            {
                ind = 0;
                setBackgroudAndText(0xfc);
                if (i == 8) std::cout << animation[0][ind] << Word(i) << " " << (statusTrack ? "On " : "Off") << animation[1][ind];
                else std::cout << animation[0][ind] << Word(i) << " " << (statusPlay ? "On " : "Off") << animation[1][ind];
                setBackgroudAndText(0xf0);
            }
            else
            {
                if (i == 8) std::cout << "    " << Word(i) << " " << (statusTrack ? "On     " : "Off    ");
                else std::cout << "    " << Word(i) << " " << (statusPlay ? "On     " : "Off    ");
            }
        }

        while (true)
        {
            gotoXY(x - 2, y + choose);
            setBackgroudAndText(0xfc);
            if (choose == 8)std::cout << animation[0][ind] << Word(choose) << " " << (statusTrack ? "On " : "Off") << animation[1][ind];
            else std::cout << animation[0][ind] << Word(choose) << " " << (statusPlay ? "On " : "Off") << animation[1][ind];
            setBackgroudAndText(0xf0);
            if (++ind == 7) ind = 0;
            if (_kbhit())
            {
                char key = _getch();
                if (key == 72 && int(choose) > 7)
                {
                    choose--;
                    break;
                }
                //up
                if (key == 80 && int(choose) <= 9)
                {
                    choose++;
                    break;
                }
                //down
                if (key == 32)
                {
                    system("cls");
                    return;
                }
                //enter
                if (key == 13)
                {
                    if (choose == Track)
                    {
                        statusTrack = !statusTrack;
                        playMusix(SOUND_TRACK, statusTrack);
                    }
                    else
                    {
                        statusPlay = !statusPlay;
                    }
                    break;
                }
                else if (key == 'q')
                {
                    endGame(quit, playing);
                    return;
                }
                else break;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
    }
}
void printRecord(user* listUser, int countUser, bool& quit, bool& playing)
{
    system("cls");
    int n = 18;
    int m = 1;
    int p = 3;
    setBackgroudAndText(0xfc);
    alphabet::printD(5 * n + p, m);
    alphabet::printR(4 * n + p, m);
    alphabet::printO(3 * n + p, m);
    alphabet::printC(2 * n + p, m);
    alphabet::printE(n + p, m);
    alphabet::printR(p, m);
    setBackgroudAndText(0xf0);

    int x = 30, y = 24;
    gotoXY(40, 22);
    std::cout << "----List of the record-----";
    for (int i = 0; i < countUser; i++)
    {
        gotoXY(x - 10, y + i);
        std::cout << "Rank " << i + 1
            << ":\tName: " << listUser[i].name
            << "\tScore: " << listUser[i].score
            << "\tTime: " << listUser[i].timePlay << "s";
    }

    if (countUser == 0)
    {
        gotoXY(x + 10, y++);
        std::cout << "No record";
    }

    gotoXY(x + 10, y + countUser + 1);
    std::cout << "----Tap space to back----";

    while (true)
    {
        if (_kbhit())
        {
            char key = _getch();
            if (key == 32)
            {
                system("cls");
                return;
            }
            else if (key == 'q')
            {
                endGame(quit, playing);
                return;
            }
        }
    }
}
void printAboutUs(bool& quit, bool& playing)
{
    system("cls");
    int n = 24;
    int m = 3;
    int p = 5;
    setBackgroudAndText(0xfc);
    alphabet::printU(p, m);
    alphabet::printS(n + p, m);
    setBackgroudAndText(0xf0);
    int oldMode = _setmode(_fileno(stdout), _O_U16TEXT);

    int x = 65, y = 8;
    gotoXY(x, y++);
    std::wcout << L"---- ĐỒ ÁN KĨ THUẬT LẬP TRÌNH ----\n"; gotoXY(x++, y++);
    std::wcout << L"        Nhóm 15 - 23CTT3"; gotoXY(x, (++y)++);
    std::wcout << L"Nguyễn Quang Duy - MSSV: 23120245"; gotoXY(x, y++);
    std::wcout << L"Lưu Trọng Hiếu   - MSSV: 23120258"; gotoXY(x, y++);
    std::wcout << L"Văn Đình Hiếu    - MSSV: 23120260"; gotoXY(x, y++);
    std::wcout << L"Nguyễn Văn Chiến - MSSV: 23120219"; gotoXY(x, y++);
    std::wcout << L"Võ Việt Anh      - MSSV: 23120213";

    gotoXY(x + 5, y + 3);
    std::wcout << L"---Tap space to back---";

    oldMode = _setmode(_fileno(stdout), oldMode);

    while (true)
    {
        if (_kbhit())
        {
            char key = _getch();
            if (key == 32)
            {
                system("cls");
                return;
            }
            else if (key == 'q')
            {
                endGame(quit, playing);
                return;
            }
        }
    }
}
char printLose(user* User, int level)
{
    system("cls");
    int n = 22;
    int m = 2;
    int p = 12;

    alphabet::printE(3 * n + p, m);
    alphabet::printS(2 * n + p, m);
    alphabet::printO(n + p, m);
    alphabet::printL(p + 5, m);

    int x = 52, y = 24;
    gotoXY(x - 5, y++);
    std::cout << "This is your result";
    gotoXY(x, y++);
    std::cout << "Name: " << User->name;
    gotoXY(x, y++);
    std::cout << "Score: " << User->score;
    gotoXY(x, y++);
    std::cout << "Time: " << User->timePlay << "s";
    gotoXY(x, y++);
    std::cout << "Level: " << level;
    gotoXY(x, y++);

    while (true)
    {
        if (_kbhit())
        {
            char key = _getch();
            if (key == 32)
            {
                return key;
            }
            else if (key == 'q')
            {
                return key;
            }
        }
    }
}
char printWin(user* User, int level)
{
    int n = 24;
    int m = 2;
    int p = 25;
    fillFullScreen(0xec);
    alphabet::printN(2 * n + p, m);
    alphabet::printI(n + p, m);
    alphabet::printW(p, m);

    int x = 52, y = 24;
    gotoXY(x - 7, y++);
    if (level > 5) std::cout << "YOU ARE THE BEST PLAYER";
    else std::cout << "Do you want to save? (y/n)";
    gotoXY(x, y++);
    std::cout << "Name: " << User->name;
    gotoXY(x, y++);
    std::cout << "Score: " << User->score;
    gotoXY(x, y++);
    std::cout << "Time: " << User->timePlay << "s";
    gotoXY(x, y++);
    std::cout << "Level: " << level;
    gotoXY(x - 5, y++);

    if (level > 5)
    {
        while (true)
        {
            if (_kbhit())
            {
                char key = _getch();
                return key;
            }
        }
    }

    while (true)
    {
        if (_kbhit())
        {
            char key = _getch();
            if (key == 'q') return key;
            else if (key == 32) return key;
            else if (key == 'y') return key;
            else if (key == 'n') return key;
        }
    }
}
char printContinue(user* User, int level)
{
    system("cls");
    int n = 13;
    int m = 2;
    int p = 3;
    setBackgroudAndText(0xfc);
    alphabet::printE(7 * n + p, m);
    alphabet::printU(6 * n + p, m);
    alphabet::printM(5 * n + p, m);
    alphabet::printI(4 * n + p, m);
    alphabet::printT(3 * n + p, m);
    alphabet::printN(2 * n + p, m);
    alphabet::printO(n + p, m);
    alphabet::printC(p, m);
    setBackgroudAndText(0xf0);

    int x = 52, y = 25;
    gotoXY(40, 24);
    std::cout << "Do you want to play continue? (y/n)";
    gotoXY(x, y++);
    std::cout << "Name: " << User->name;
    gotoXY(x, y++);
    std::cout << "Score: " << User->score;
    gotoXY(x, y++);
    std::cout << "Time: " << User->timePlay << "s";
    gotoXY(x, y++);
    std::cout << "Level: " << level;
    while (true)
    {
        if (_kbhit())
        {
            char key = _getch();
            if (key == 'y') return key;
            if (key == 'n') return key;
            if (key == 'q') return key;
        }
    }
}
void endGame(bool& _quit_, bool& _Playing_)
{
    _quit_ = true;
    _Playing_ = false;
}

void _printInformation(const int x, const int y, bool& _Playing_, user* User, const snake& Snake,
    const bool& next, const int level)
{
    setBackgroudAndText(0xfc);
    gotoXY(x + 5, y);
    std::cout << "---TARGET---";
    gotoXY(x + 5, y + 1);
    switch (level)
    {
    case 1:
        std::cout << "Eat 5 food";
        break;
    case 2:
        std::cout << "Eat 7 food";
        break;
    case 3:
        std::cout << "Eat 5 food";
        break;
    case 4:
        std::cout << "  Live in 30s ";
        gotoXY(x + 4, y + 2);
        std::cout << "and Eat 3 food";
        break;
    case 5:
        std::cout << "Live in 60s";
        break;
    }
    gotoXY(x + 8, y + 4);
    std::cout << User->name;
    setBackgroudAndText(0xf0);
    gotoXY(x, y + 4);
    std::cout << "Name: ";
    gotoXY(x, y + 5);
    std::cout << "Score: ";
    gotoXY(x, y + 6);
    std::cout << "Time: ";
    gotoXY(x, y + 7);
    std::cout << "Length: ";
    gotoXY(x, y + 8);
    std::cout << "Speed: ";
    gotoXY(x, y + 11);
    std::cout << "Press 'q' to exit";
    gotoXY(x, y + 12);
    std::cout << "Press 'space' to pause";
    gotoXY(x, y + 13);
    std::cout << "Press 'space' to start";
    gotoXY(x, y + 14);
    std::cout << "Press 'm' to turn";
    gotoXY(x, y + 15);
    std::cout << "   on/off music";

    while (_Playing_ && !next)
    {
        mtx.lock();
        (User->timePlay)++;
        setBackgroudAndText(0xfc);
        gotoXY(x + 8, y + 5);
        std::cout << User->score;
        gotoXY(x + 8, y + 6);
        std::cout << User->timePlay << "s";
        gotoXY(x + 8, y + 7);
        std::cout << Snake.length;
        gotoXY(x + 8, y + 8);
        std::cout << Snake.speed;
        setBackgroudAndText(0xf0);
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
void _snakePlay(snake& _snake_, food& _food_, door& door, obstacle** theMap, const direction& dir,
    user* player, bool& playing, const int& level, bool& next)
{
    bool isImpact = false;
    direction test = dir;
    const int timeStart = player->timePlay;
    _food_.live = false;
    if (!game::conditionFood(_snake_, player, level)) _food_.makeFood(_snake_, theMap);
    _snake_.resetSnake();

    if (level == 5) _snake_.speed = SNAKE_MAX_SPEED;

    while (playing && !game::checkTarget(_snake_, player, level, timeStart))
    {
        mtx.lock();
        if ((test == UP || test == DOWN) && (dir == LEFT || dir == RIGHT))
        {
            test = dir;
        }
        else if ((test == LEFT || test == RIGHT) && (dir == UP || dir == DOWN))
        {
            test = dir;
        }

        if (eatFood(_snake_, _food_, player)
            && !game::conditionFood(_snake_, player, level)) _food_.makeFood(_snake_, theMap);
        _food_.drawFood();

        moveSnake(_snake_, test);
        impactItself(_snake_, isImpact);
        impactWall(_snake_, theMap, isImpact);

        if (isImpact)
        {
            playing = false;
        }

        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(int(1000 / _snake_.speed)));
    }

    if (playing) door.makeDoor(_snake_, theMap);
    while (playing && !next)
    {
        mtx.lock();

        if ((test == UP || test == DOWN) && (dir == LEFT || dir == RIGHT))
        {
            test = dir;
        }
        else if ((test == LEFT || test == RIGHT) && (dir == UP || dir == DOWN))
        {
            test = dir;
        }

        moveSnake(_snake_, test);
        impactItself(_snake_, isImpact);
        impactWall(_snake_, theMap, isImpact);
        impactDoor(_snake_, door, isImpact, next);

        if (isImpact)
        {
            playing = false;
        }

        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(int(1000 / _snake_.speed)));
    }
    while (playing && _snake_.length)
    {
        mtx.lock();
        gotoXY(_snake_.body[_snake_.length - 1].x, _snake_.body[_snake_.length - 1].y);
        std::cout << " ";
        _snake_.length--;
        drawSnake(_snake_);
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(int(1000 / _snake_.speed)));
    }
    if (playing && level == 5) player->score += 20;
}
void _monsterPlay(snake& _snake_, obstacle** theMap, food& Food, bool& playing, const int& level, bool& next)
{
    if (level == 3)
    {
        while (playing && !next)
        {
            mtx.lock();
            game::typeOne::updateBullet(theMap, Food);
            game::typeOne::drawBullet();
            if (game::typeOne::checkImpact(_snake_))
            {
                playing = false;
            }
            mtx.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(int(1000 / _snake_.speed)));
        }
    }
    else if (level == 4)
    {
        game::typeTwo::monster Monster;
        while (playing && !next)
        {
            mtx.lock();
            Monster.moveKiller(_snake_, theMap);
            Monster.drawKiller();
            if (Monster.checkKill(_snake_, theMap))
            {
                playing = false;
            }
            mtx.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(int(1000 / Monster.speed)));
        }
    }
    else if (level == 5)
    {
        game::typeThree::monster Monster;
        while (playing && !next)
        {
            mtx.lock();
            Monster.moveKiller(_snake_, theMap);
            Monster.drawKiller();
            if (Monster.checkKill(_snake_, theMap))
            {
                playing = false;
            }
            Monster.makeBullet(_snake_, theMap);
            //2 nhịp đạn 1 nhịp boss
            Monster.Draw_MoveBullet(theMap);
            if (Monster.checkBullet(_snake_, theMap))
            {
                playing = false;
            }
            Monster.Draw_MoveBullet(theMap);
            if (Monster.checkBullet(_snake_, theMap))
            {
                playing = false;
            }
            mtx.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(int(1000 / Monster.speedKill)));
        }
    }
}