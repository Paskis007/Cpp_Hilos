#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <thread>
#include "background_task.h"
#define _CRT_SECURE_NO_WARNINGS


void oops();
void do_something(int i);

int main()
{
    
    oops();
    return 0;    
}

struct func
{
    int& i;
    func(int& i_) :i(i_) {}
    void operator()()
    {
        for (unsigned j = 0; j < 100; ++j)
        {
            do_something(i);
        }
    }
};
void oops()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    //my_thread.detach();
    my_thread.join();
    std::cout << "Hello, World something!" << std::to_string(some_local_state) << std::endl;
}
void do_something(int i)
{
    //std::cout << "Hello, World something!" << std::to_string(i) << std::endl;
}
