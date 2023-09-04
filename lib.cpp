#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>

class Timer{
    int min;
    std::string path;
    std::fstream out;
    const char* currentTime;

    void exitProgramm(){
                currentTime = std::ctime(&start);//convert time fot char[]
                out << "\nbreak programm:( " << currentTime <<'\n';
                out.close();
        return;
    }

    //300 seconds pause 
    void pause(){
        for(int i = 300; i > 0; --i){
            std::cout << "\ntime-out seconds: " << i << '\n';
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    //work programm and chouse for hide menu
    void work(){
        while(min > 0){
            --min;
                for(int i = 59; i > 0; --i){
                std::cout << "\nTime of minuts: " << min << " seconds: " << i << '\n';
                std::this_thread::sleep_for(std::chrono::seconds(1));
                
                //time out block and leason 
                if(_kbhit()){
                char ch = getch();

                    switch(ch){
                        case 112: pause();break;
                        case 27: exitProgramm(); goto EXIT;break;
                        default: continue;
                    }
                }
                }       
        }//while

        currentTime = std::ctime(&start);//convert time fot char[]

        out << "\n25 min of learn to executed! well done!!!\n" << currentTime <<'\n';
        out.close();

        EXIT:
        Beep(2000,1000);
    }

    public:
    std::time_t start;

    Timer(int value, std::string path_):min(value),path(path_), start(std::time(0)){
        out.open(path,std::ios_base::app);

        if(!out.is_open()){
            bool openFile = false;

            while(!openFile){
                std::cout << "path not found/ file.txt!\npress enter try again path: ";
                std::cin >> path;
                if(out.is_open()){
                    openFile = true;
                }
            }
        }
    }

    void startTimer(){
        char select ='\0';

        while(true){
            std::cout << "press start timer 'S' and 'ESC' to exit: ";
            std::cin >> select;

            if(select == 27){
                break;
            }
            else if(select == 115){
                work();
            }
        }
        return;
    }

     ~Timer(){}
};