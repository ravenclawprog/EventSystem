#include <iostream>
#include "src/include/delegate.h"
struct Obj{
    void call(const void* sender) {
        std::cout << "Calling call" << std::endl;
    }
    void callInt(const void* sender, int* param) {
        std::cout << "Calling call with param:" << *param << std::endl;
    }
};
int main()
{
    std::cout << "Hello, world!" << std::endl;
    Obj* a = new Obj{};
    ES::Delegate dl(a, &Obj::callInt);
    int i = 10;
    dl.notify(nullptr, &i);
    delete a;
    return 0;
}