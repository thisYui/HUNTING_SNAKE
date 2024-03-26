#include "console.h"
#include "UI.h"
#include "object.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <conio.h>

extern const int MATRIX_SIZE_HEIGHT;
extern const int MATRIX_SIZE_WIDTH;

void sortByScore(user* listUser, const int& countUser);
void sortByTime(user* listUser, const int& countUser);
bool readData(std::string& _Name_, int& _Score_, int& _TimePlay_, int& _Level_);
//đọc dữ liệu từ file data.txt xem người chơi có muốn chơi tiếp không
void writeData(bool _PlayContinue_, std::string& _Name_, int& _Score_, int& _TimePlay_, int& _Level_);
//ghi dữ liệu vào file data.txt nếu người chơi muốn chơi tiếp
void readRecord(user*& listUser, int& countUser);
//đọc dữ liệu từ file record.txt
void addUserData(user*& listUser, int& countUser, const std::string& _Name_, int _Score_, int _TimePlay_);
//thêm dữ liệu người chơi vào list
void updateRecord(user*& listUser, const int& countUser);
//cập nhật dữ liệu vào file record.txt

int main()
{
    //khai biến Playing và ma trận tạo map game
    bool _quit_ = false;
    obstacle** theMap = new obstacle*[MATRIX_SIZE_HEIGHT];
    for (int i = 0; i < MATRIX_SIZE_HEIGHT; i++)
    {
		theMap[i] = new obstacle[MATRIX_SIZE_WIDTH];
	}

    //chuyen console sang unicode
    
    do
    {
        //thiết đặt các chế độ và thông số cho console
        init();

        //bien luu tru thong tin nguoi choi
        bool _Playing_ = true; 
        int _Level_ = 1;
        user* player = new user;
        snake _snake_;
        clock_t start = clock();
        inforName(player, 1, 1);
        /*if (!readData(_Name_, _Score_, _TimePlay_, _Level_))
        {
            inforName(_Name_);
            _Level_ = 1;
            _Score_ = 0;
            _TimePlay_ = 0.0;
        }*/
        while (_Playing_)
        {
            game::initMap(theMap);
            switch (_Level_)
            {
            case 1:
                game::initLevel_1(theMap);
                break;
            case 2:
                game::initLevel_2(theMap);
                break;
            case 3:
                game::initLevel_3(theMap);
                break;
            case 4:
                game::initLevel_4(theMap);
                break;
            case 5:
                game::initLevel_5(theMap);
                break;
            default:
                game::drawWin();
                break;
            }
            game::initLevel_2(theMap);
            game::drawMap(theMap, 1, 1, _Level_);

            std::thread information(printInformation, 
                MATRIX_SIZE_WIDTH - MATRIX_SIZE_HEIGHT + 5, 3, std::ref(_Playing_), player, std::ref(_snake_));
            direction key = direction::RIGHT;

            while(_Playing_)
            {    

                //Sleep(1000);
                ///vòng lặp chính của game
                
                if (_kbhit())
                {
                    moveSnake(_snake_, key);
                    char test = _getch();
                    if(test == 72) key = direction::UP;
					else if(test == 80) key = direction::DOWN;
					else if(test == 75) key = direction::LEFT;
					else if(test == 77) key = direction::RIGHT;
					else if(test == 27)
					{
						_Playing_ = false;
						_quit_ = true;
					}
                }
                else
                {
					moveSnake(_snake_, key);
				}
                endGame(_quit_, _Playing_);
            }

            information.join();
        }

        delete player;

    }while(!_quit_);

    for (int i = 0; i < MATRIX_SIZE_HEIGHT; i++)
    {
		delete[] theMap[i];
	}
    delete[] theMap;

	return 0;
}

void sortByScore(user* listUser, const int& countUser)
{
    for (int i = 0; i < countUser; i++)
    {
        for (int j = i + 1; j < countUser; j++)
        {
            if (listUser[i].score < listUser[j].score)
            {
				user tmp = listUser[i];
				listUser[i] = listUser[j];
				listUser[j] = tmp;
			}
		}
	}
}
void sortByTime(user* listUser, const int& countUser)
{
    for (int i = 0; i < countUser; i++)
    {
        for (int j = i + 1; j < countUser; j++)
        {
            if (listUser[i].score == listUser[j].score)
            {
                if (listUser[i].timePlay > listUser[j].timePlay)
                {
					user tmp = listUser[i];
					listUser[i] = listUser[j];
					listUser[j] = tmp;
				}
			}
		}
	}
}
bool readData(std::string& _Name_, int& _Score_, int& _TimePlay_, int& _Level_)
{
    std::fstream file;
    file.open("data.txt", std::ios::in);

    //5 dòng
    if (file.is_open())
    {
        while (!file.eof())
        {
            std::string buffer;

            getline(file, buffer);//dòng 1 kiểm tra xem người chơi có muốn chơi tiếp không
            if (std::stoi(buffer) == 0) return false;//người chơi không lưu thì phải chơi lại từ đầu

            getline(file, buffer);//dòng 2 tên người chơi
            _Name_ = buffer;

            getline(file, buffer);//dòng 3 điểm người chơi
            _Score_ = std::stoi(buffer);

            getline(file, buffer);//dòng 4 thời gian chơi
            _TimePlay_ = std::stoi(buffer);

            getline(file, buffer);//dòng 5 level người chơi
            _Level_ = std::stoi(buffer);
        }

        file.close();
    }
    else std::cerr << "Can't open file" << std::endl;
    return true;
}
void writeData(bool _PlayContinue_, std::string& _Name_, int& _Score_, int& _TimePlay_, int& _Level_)
{
    std::fstream file;
    file.open("data.txt", std::ios::out);
    if (file.is_open())
    {
        file << _PlayContinue_ << std::endl;
        file << _Name_ << std::endl;
        file << _Score_ << std::endl;
        file << _TimePlay_ << std::endl;
        file << _Level_;//không dùng endl nếu dùng sẽ dư 1 dòng gây ra lỗi
        file.close();
    }
    else std::cerr << "Can't open file" << std::endl;
}
void readRecord(user*& listUser, int& countUser)
{
    std::fstream file;
    file.open("record.txt", std::ios::in);

    if (file.is_open())
    {
        std::string buffer;
        getline(file, buffer);
        countUser = std::stoi(buffer);
        //+1 vì người chơi hiện tại chưa được thêm vào file record.txt
        listUser = new user[countUser + 1];
        
        while (!file.eof())
        {
            getline(file, buffer);
            if (buffer == "end") break;//end là dấu hiệu kết thúc file

            getline(file, buffer);
            listUser[countUser].name = buffer;
            getline(file, buffer);
            listUser[countUser].score = std::stoi(buffer);
            getline(file, buffer);
            listUser[countUser].timePlay = std::stoi(buffer);
            
            countUser++;
        }
        file.close();
    }
    else std::cerr << "Can't open file" << std::endl;
}
void addUserData(user*& listUser, int& countUser, const std::string& _Name_, int _Score_, int _TimePlay_)
{
    countUser++;
    listUser[countUser].name = _Name_;
    listUser[countUser].score = _Score_;
    listUser[countUser].timePlay = _TimePlay_;

    sortByScore(listUser, countUser);
    sortByTime(listUser, countUser);
}
void updateRecord(user*& listUser, const int& countUser)
{
    const int MAX_USER = 5;
    int sum;
    if (countUser < MAX_USER) sum = countUser;
	else sum = MAX_USER;

    std::fstream file;
    file.open("record.txt", std::ios::out);
    if (file.is_open())
    {
        file << sum << std::endl;
        for (int i = 0; i < sum; i++)
        {
            file << listUser[i].name << std::endl;
            file << listUser[i].score << std::endl;
            file << listUser[i].timePlay << std::endl;
        }
        file << "end";
        file.close();
    }
    else std::cerr << "Can't open file" << std::endl;

    delete[] listUser;
}
