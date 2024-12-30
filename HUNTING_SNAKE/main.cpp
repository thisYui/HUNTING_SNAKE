#include "console.h"
#include "UI.h"
#include "object.h"
#include <fstream>

extern const int MATRIX_SIZE_HEIGHT;
extern const int MATRIX_SIZE_WIDTH;
extern const char* SOUND_TRACK;
extern const char* SOUND_PLAY;
extern std::mutex mtx;

static void sortUser(user*& listUser, const int& countUser);
static void freeUserMemory(user*& listUser);
bool readData(user*& player, int& _Level_);
//đọc dữ liệu từ file data.txt xem người chơi có muốn chơi tiếp không
void writeData(const bool _PlayContinue_, user*& player, const int& _Level_);
//ghi dữ liệu vào file data.txt nếu người chơi muốn chơi tiếp
void readRecord(user*& listUser, int& countUser);
//đọc dữ liệu từ file record.txt
void addUserData(user*& listUser, int& countUser, user*& player);
//thêm dữ liệu người chơi vào list
void updateRecord(user*& listUser, int& countUser, user*& player);
//cập nhật dữ liệu vào file record.txt

int main()
{
    //khai biến quiet và ma trận tạo map game
    bool _quit_ = false;
    obstacle** theMap = new obstacle * [MATRIX_SIZE_HEIGHT];
    for (int i = 0; i < MATRIX_SIZE_HEIGHT; i++)
    {
        theMap[i] = new obstacle[MATRIX_SIZE_WIDTH];
    }

    bool soundTrack = true;
    bool soundPlay = true;

    do
    {
        //thiết đặt các chế độ và thông số cho console
        playMusix(SOUND_TRACK, soundTrack);
        if (init() == 'q')
        {
            _quit_ = true;
            break;
        }

        bool _Playing_ = false;
        int _Level_ = 1;
        user* player = new user;

        user* record = nullptr;
        int countUser = 0;

        //menu chính
        readRecord(record, countUser);
        do
        {
            switch (printMenu())
            {

            case Word::StartGame:
            {
                _Playing_ = true;
                if (!readData(player, _Level_))
                {
                    inforName(player);
                    _Level_ = 5;
                    player->score = 0;
                    player->timePlay = 0;
                }
                else
                {
                    switch (printPlay())
                    {
                    case Word::NewGame:
                    {
                        inforName(player);
                        _Level_ = 1;
                        player->score = 0;
                        player->timePlay = 0;
                        break;
                    }
                    case Word::Continue:
                    {
                        _Playing_ = true;
                        break;
                    }
                    case Word::Exit:
                    {
                        _quit_ = true;
                        _Playing_ = false;
                        freeUserMemory(record);
                        break;
                    }
                    }
                }
                break;
            }
            case Word::Setting:
            {
                setMusic(soundTrack, soundPlay, _quit_, _Playing_);
                break;
            }
            case Word::History:
            {
                printRecord(record, countUser, _quit_, _Playing_);
                break;
            }
            case Word::About:
            {
                printAboutUs(_quit_, _Playing_);
                break;
            }
            case Word::Exit:
            {
                freeUserMemory(record);
                endGame(_quit_, _Playing_);
                break;
            }
            }
        } while (!_Playing_ && !_quit_);

        std::thread information;
        std::thread snakePlay;
        std::thread killer;

        //----------play game----------//
        while (_Playing_)
        {
            system("cls");

            snake _snake_;
            food _food_;
            door _door_;
            direction dir = direction::RIGHT;

            bool next = false;

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
                char check = printWin(player, _Level_);
                if (check == 'q') endGame(_quit_, _Playing_);
                _Playing_ = false;
                writeData(false, player, _Level_);
                updateRecord(record, countUser, player);
                break;
            }
            if (!_Playing_)
            {
                system("cls");
                break;
            }
            game::drawMap(theMap, 1, 1, _Level_);

            //man hình thông tin
            information = std::thread(_printInformation,
                MATRIX_SIZE_WIDTH - MATRIX_SIZE_HEIGHT + 5, 5,
                std::ref(_Playing_), player, std::ref(_snake_),
                std::ref(next), std::ref(_Level_));
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            //rắn
            snakePlay = std::thread(_snakePlay,
                std::ref(_snake_), std::ref(_food_), std::ref(_door_),
                theMap, std::ref(dir), player, std::ref(_Playing_),
                std::ref(_Level_), std::ref(next));
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            //killer
            if (_Level_ > 2)
            {
                killer = std::thread(_monsterPlay,
                    std::ref(_snake_), theMap, std::ref(_food_),
                    std::ref(_Playing_), std::ref(_Level_), std::ref(next));
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
            //âm thanh
            playMusix(SOUND_PLAY, soundPlay);

            //chuẩn bị
            mtx.lock();
            while (true)
            {
                if (_kbhit())
                {
                    char noPause = _getch();
                    if (noPause == 32) break;
                    if (noPause == 'q')
                    {
                        endGame(_quit_, _Playing_);
                        break;
                    }
                }
            }
            mtx.unlock();

            ///------MAIN THREAD------///
            while (_Playing_ && !next)
            {
                mtx.lock();
                if (_kbhit())
                {
                    char keyboard = _getch();
                    switch (keyboard)
                    {
                    case 72:
                        dir = direction::UP;
                        break;
                    case 80:
                        dir = direction::DOWN;
                        break;
                    case 75:
                        dir = direction::LEFT;
                        break;
                    case 77:
                        dir = direction::RIGHT;
                        break;
                    case 'q':
                        writeData(false, player, _Level_);
                        freeUserMemory(record);
                        endGame(_quit_, _Playing_);
                        break;
                    case 'm':
                        soundPlay = !soundPlay;
                        playMusix(SOUND_PLAY, soundPlay);
                        break;
                    case 32: //space
                        while (true)
                        {
                            if (_kbhit())
                            {
                                char noPause = _getch();
                                if (noPause == 32) break;
                                if (noPause == 'q')
                                {
                                    endGame(_quit_, _Playing_);
                                    freeUserMemory(record);
                                    break;
                                }
                            }
                        }
                        break;
                    }
                }
                mtx.unlock();
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                //100ms là thời gian delay giữa các lần lặp nhằm hạn chế quá tải từ keyboard
            }

            information.join();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            snakePlay.join();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            if (_Level_ > 2) killer.join();

            if (_quit_) break;

            if (!_Playing_)
            {
                char check = printLose(player, _Level_);
                if (check == 'q')
                {
                    endGame(_quit_, _Playing_);
                }
                _Playing_ = false;
                writeData(false, player, _Level_);
                updateRecord(record, countUser, player);
            }
            else if (_Level_ != 5)
            {
                char check = printContinue(player, _Level_);
                if (check == 'n')
                {
                    _Playing_ = false;
                    char key = printWin(player, _Level_);
                    if (key == 'q')
                    {
                        writeData(false, player, _Level_);
                        updateRecord(record, countUser, player);
                        endGame(_quit_, _Playing_);
                    }
                    else if (key == 'n')
                    {
                        writeData(false, player, _Level_);
                        updateRecord(record, countUser, player);
                    }
                    else if (key == 'y')
                    {
                        writeData(true, player, _Level_ + 1);
                    }
                }
                else if (check == 'q')
                {
                    writeData(false, player, _Level_);
                    endGame(_quit_, _Playing_);
                }
                else if (check == 'y') _Level_++;
            }
            else if (_Level_ == 5) _Level_++;
        }
        delete player;
        system("cls");

    } while (!_quit_);

    for (int i = 0; i < MATRIX_SIZE_HEIGHT; i++)
    {
        delete[] theMap[i];
    }
    delete[] theMap;

    closeConsole();
    return 0;
}

static void sortUser(user*& listUser, const int& countUser)
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
    for (int i = 0; i < countUser - 1; i++)
    {
        if (listUser[i].score == listUser[i + 1].score)
        {
            int j = i;
            while (listUser[j].score == listUser[j + 1].score) j++;
            for (int k = i; k < j; k++)
            {
                for (int l = k + 1; l <= j; l++)
                {
                    if (listUser[k].timePlay > listUser[l].timePlay)
                    {
                        user tmp = listUser[k];
                        listUser[k] = listUser[l];
                        listUser[l] = tmp;
                    }
                }
            }
        }
    }
}
void freeUserMemory(user*& listUser)
{
    delete[] listUser;
    listUser = nullptr;
}
bool readData(user*& player, int& _Level_)
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
            player->name = buffer;

            getline(file, buffer);//dòng 3 điểm người chơi
            player->score = std::stoi(buffer);

            getline(file, buffer);//dòng 4 thời gian chơi
            player->timePlay = std::stoi(buffer);

            getline(file, buffer);//dòng 5 level người chơi
            _Level_ = std::stoi(buffer);
        }

        file.close();
    }
    else std::cerr << "Can't open file" << std::endl;
    return true;
}
void writeData(const bool _PlayContinue_, user*& player, const int& _Level_)
{
    std::fstream file;
    file.open("data.txt", std::ios::out);
    if (file.is_open())
    {
        file << _PlayContinue_ << std::endl;
        file << player->name << std::endl;
        file << player->score << std::endl;
        file << player->timePlay << std::endl;
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
        if (buffer == "this_end_file@#$") return;
        countUser = std::stoi(buffer);
        //+1 vì người chơi hiện tại chưa được thêm vào file record.txt
        listUser = new user[countUser + 1];
        countUser = 0;

        while (!file.eof())
        {
            getline(file, buffer);
            if (buffer == "this_end_file@#$") break;//end là dấu hiệu kết thúc file
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
void addUserData(user*& listUser, int& countUser, user*& player)
{
    listUser[countUser].name = player->name;
    listUser[countUser].score = player->score;
    listUser[countUser].timePlay = player->timePlay;
    countUser++;

    sortUser(listUser, countUser);
}
void updateRecord(user*& listUser, int& countUser, user*& player)
{
    addUserData(listUser, countUser, player);
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
        file << "this_end_file@#$";//kí tự phải đủ đặc biệt để ko thể trùng tên người chơi
        file.close();
    }
    else std::cerr << "Can't open file" << std::endl;

    freeUserMemory(listUser);
}