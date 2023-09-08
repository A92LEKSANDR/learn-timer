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
    int minuts;
    std::string path;
    //engane Timer in private
    class Framework{
        int minuts;
        std::time_t startTime;//keep current time
        const char* currentTime;//from convert time in string
        std::ofstream out;//save advances

        public:
        Framework(){}

        Framework(int min, std::string path_):minuts(min),startTime(std::time(0)),currentTime(std::ctime(&startTime)){
            out.open(path_,std::ios_base::app);
        }

        void start(){
            //timeout seconds
            bool exit = false;
            while(minuts > 0 || exit != true){
                --minuts;
                for(int i = 59; i > 0; --i){//display seconds
                    if(_kbhit()){
                        switch(_getch()){
                            case 'q':
                                exit = true;
                                break;
                            case 'p': 
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
                                break;
                                default: std::cout << "p - pause / q - quit\n";
                        }   

                    }//if pressed key
                    else if(exit){
                        break;
                    }
                    std::cout << "minuts: " <<  minuts << " seconds: " << i << '\n';// winapi dont show
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }        
            }//while basic
            out << currentTime << " - 25 minuts work, well done!!!\n";
        }//START

        ~Framework(){ }
    };//framework end

    Framework* framework;
    public:

    Timer(int minuts_, std::string path_):minuts(minuts_),path(path_){
    }

    void start(){
        char select;
        do{
            std::cout << "press to S for start and continue timer or\npress q to quit:";
            select = getInput();

            if(select == 's'){
                framework = new Framework{minuts,path};
                framework->start();
                delete framework;
            }
        }while(select != 'q');

        std::cout << "program exit, goodbye!!!\n";
    }

     ~Timer(){}
};