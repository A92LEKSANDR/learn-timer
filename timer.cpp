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
    public:
    Timer(int value, std::string path_):min(value),path(path_){}

    void start(){
        std::time_t start = std::time(0);//?

        while(min > 0){
            --min;
             for(int i = 59; i > 0; --i){
             std::cout << "\nTime of minuts: " << min << " seconds: " << i << '\n';
             std::this_thread::sleep_for(std::chrono::seconds(1));//?
            
            //time out block
            if(_kbhit()){
            char ch = _getch();
                if(ch == 'p' || ch == 'P'){
                    //SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);
                    for(int i = 300; i > 0; --i){
                    std::cout << "\ntime-out seconds: " << i << '\n';
                    std::this_thread::sleep_for(std::chrono::seconds(1));//?
    
                }
            }
        }
    }
             
}//while

        //save txt information time and turn off display
        std::fstream out;
        out.open(path,std::ios_base::app);

        //block code for protection error input
        if(!out.is_open()){
            bool open = false;
            while(!open){
                std::cout << "path not found/ file.txt!\npress enter try again path: ";
                std::cin >> path;
                if(out.is_open()){
                    open = true;
                }
            }
        }//

        const char* currentTime = std::ctime(&start);//convert time fot char[]

        out << "\ncurrent time: " << currentTime << "\n25 minuts of learn\nand five minuts time-out";
        out.close();

        SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);//turn off display
        
    }
};

int main(){

    Timer timer(25, "C:/timer.txt"); // where be win application, press button chouse and input text
    char option{'\0'};

    do{
        timer.start();
        std::cout << "press enter y to continue/press enter n to exit: ";

        std::cin >> option;

    }while(option != 'n');
    

    return 0;
}