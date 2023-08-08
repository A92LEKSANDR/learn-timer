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
    public:
    Timer(int value, std::string path_):min(value),path(path_){
            //block code for protection error input
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
        }//
    }

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
       

        const char* currentTime = std::ctime(&start);//convert time fot char[]

        out << "\ncurrent time: " << currentTime << "25 minuts of learn\nand five minuts time-out";
        out.close();

        SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);//turn off display
        
    }

     ~Timer(){}
};

int main(){

    //Timer timer(1, "C:/learn.txt"); // where be win application, press button chouse and input text
    char option{'\0'};
    Timer* list = nullptr;

    do{
        list = new Timer{1,"C:/learn.txt"};
        list->start();

        std::cout << "press enter y to continue/press enter n to exit: ";
        
        list->~Timer();

        std::cin >> option;

    }while(option != 'n');
    

    return 0;
}