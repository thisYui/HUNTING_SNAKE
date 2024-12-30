#include "console.h"

void disableResizeWindow()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
void disableCtrButton(bool Close, bool Min, bool Max)
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);

    if (Close == 1)
    {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (Min == 1)
    {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Max == 1)
    {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}
void showScrollbar(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}
void resizeConsole(int width, int height) {
    HWND console = GetConsoleWindow();
    RECT rect;
    GetWindowRect(console, &rect);
    MoveWindow(console, rect.left, rect.top, width, height, TRUE);
}
void gotoXY(int x, int y) {
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x - 1, y - 1 };
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void setBackgroudAndText(int code) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, code);
}
void noneCursorType(bool cursor)
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = cursor;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void setFontSize(int height = FONT_SIZE, int width = FONT_SIZE)
{
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(fontInfo);
    fontInfo.nFont = 0;
    fontInfo.dwFontSize.X = width;
    fontInfo.dwFontSize.Y = height;
    fontInfo.FontFamily = FF_DONTCARE;
    fontInfo.FontWeight = FW_NORMAL;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &fontInfo);
}
void setConsoleTitle(const char* title)
{
    SetConsoleTitleA(title);
}
void setConsoleIcon(const char* iconPath)
{
    HWND console = GetConsoleWindow();
    HICON icon = (HICON)LoadImageA(NULL, iconPath, IMAGE_ICON, 32, 32, LR_LOADFROMFILE);
    SendMessageA(console, WM_SETICON, ICON_SMALL, (LPARAM)icon);
    SendMessageA(console, WM_SETICON, ICON_BIG, (LPARAM)icon);
}
void disableTextSelection() {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD prev_mode;
    GetConsoleMode(hInput, &prev_mode);
    SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS | (prev_mode & ~ENABLE_QUICK_EDIT_MODE));
}
void disableConsoleDragging() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style &= ~WS_THICKFRAME; // Loại bỏ khả năng kéo cửa sổ
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void closeConsole()
{
    ExitProcess(0);
}