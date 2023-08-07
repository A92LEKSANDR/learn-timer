#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <ctime>
#include <Windows.h>

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
              }
             
        }//while
        std::fstream out;
        out.open("C:/learn.txt",std::ios_base::app);

        const char* currentTime = std::ctime(&start);//convert to char[]

        out << "current time: " << currentTime << "\n25 minuts of leartn\nand five minuts time-out\n";
        out.close();

        SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);
        
    }
};

int main(){

    Timer timer(25);
    timer.start();

    return 0;
}