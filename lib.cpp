#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <tchar.h>

char getInput(){
    char select;
    bool input = false;

    while(!input){
        std::cin >> select;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else if(!std::cin.fail()){
            input = true;
        }
    }
    return select;
}


class Timer{
    //engane Timer in private
    class Framework{
        uint8_t minuts;
        std::time_t startTime;//keep current time
        const char* currentTime;//from convert time in string
        std::ofstream out;//save advances

        public:
        Framework(){}

        Framework(uint8_t min, std::string path_):minuts(min),startTime(std::time(0)),currentTime(std::ctime(&startTime)){
            out.open(path_,std::ios_base::app);
        }

        void start(){
            //timeout seconds
            while(minuts > 0){
                --minuts;
                for(int i = 59; i >= 0; --i){
                    if(_kbhit()){
                        //std::cout << "key pressed\n";
                        char ch = _getch();
                        if(ch == 'q'){
                            break;//exit in basic while()
                        }
                        else if(ch == 'p'){
                            for(int i = 300; i > 0; --i){
                                if(_kbhit()){
                                    char ch = _getch();
                                    if(ch == 'q'){
                                        break;//exit in inner while(pause)
                                    }
                                }
                                std::cout << "time-out:"<< i << '\n';// winapi dont show
                                std::this_thread::sleep_for(std::chrono::seconds(1));
                            }
                            out << currentTime << " - 5 minuts time-out\n";
                        }
                    }//if pressed key

                    std::cout << "seconds: " << i << '\n';// winapi dont show
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }        
            }//while basic
            out << currentTime << " - 25 minuts work, well done!!!\n";
        }//START

        ~Framework(){ }
    };//framework end

    Framework framework;
    public:

    Timer(uint8_t minuts, std::string path_):framework(minuts,path_){}

    void start(){
        char select;
        while(select != 'q'){
            framework.start();
            std::cout << "continue?\npress c or q to quit:";
            select = getInput();
        }
        std::cout << "program exit, goodbye!!!\n";
    }

     ~Timer(){ }
};