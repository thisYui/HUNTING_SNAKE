#pragma once
#ifndef _THE_CONSOLE
#define _THE_CONSOLE

#include <Windows.h>
const int FONT_SIZE = 20;

void disableResizeWindow();// vô hiệu hóa nút resize console
void disableCtrButton(bool Close, bool Min, bool Max);// vô hiệu hóa nút close, minimize, maximize
void showScrollbar(BOOL Show);//ẩn thanh cuộn
void resizeConsole(int width, int height);// thay đổi kích thước console
void gotoXY(int x, int y);// di chuyển con trỏ đến vị trí x, y
void setBackgroudAndText(int code);// thay đổi màu nền và màu chữ
//nếu code có dạng hecxa 0xnab thì a là màu nền, b là màu chữ
//n: 0-3 ko đổi, 4-7 kẻ ngang, 8-11 kẻ dọc, 12-15 kẻ caro
//hay n(0-15) << 8 | a << 4 | b hoặc n(0-3) << 10 | a << 4 | b
void noneCursorType(bool cursor);// ẩn con trỏ
void setFontSize(int height, int width);// thay đổi kích thước font chữ
void setConsoleTitle(const char* title);// thay đổi tiêu đề console
void setConsoleIcon(const char* iconPath);// thay đổi icon console
void disableTextSelection();// vô hiệu hóa chọn text
void disableConsoleDragging();// vô hiệu hóa kéo thả console
void closeConsole();// đóng console

#endif // !_THE_CONSOLE