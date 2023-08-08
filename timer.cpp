#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <ctime>
#include <Windows.h>
#include <conio.h>

class Timer{
    int min;
    public:
    Timer(int value):min(value){}

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
        std::fstream out;
        out.open("C:/learn.txt",std::ios_base::app);

        const char* currentTime = std::ctime(&start);

        out << "\ncurrent time: " << currentTime << "\n25 minuts of learn\nand five minuts time-out";
        out.close();

        SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);
        
    }
};

int main(){

    Timer timer(25);
    timer.start();

    return 0;
}