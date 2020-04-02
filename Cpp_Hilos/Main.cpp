#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <thread>
#include "background_task.h"
#define _CRT_SECURE_NO_WARNINGS


void hello();
void do_something();
void do_something_else();
int main()
{
    std::cout << "Hello, World!" << std::endl;
    //std::cin.ignore();
    int size = 1024;
    std::vector<int> a(size);

    std::thread t(hello);
    t.join();

    //background_task f;

   // std::thread my_thread{ background_task() };


    
    std::thread my_thread([] {
        do_something();
        do_something_else();
        });

    my_thread.join();

    return 0;    
}
void hello()
{
    std::cout << "Hello Concurrent World\n";
}

void do_something() 
{
    std::cout << "Hello, World cosa!" << std::endl;
}
void do_something_else() 
{
    std::cout << "Hello, World cosa_2!" << std::endl;
}

