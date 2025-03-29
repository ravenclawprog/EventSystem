#include <iostream>
#include "src/include/template/abstract_delegate.h"
#include "src/include/template/delegate.h"
#include "src/include/template/basic_event.h"

struct Obj{
    Obj() : _name("default name") {}
    Obj(const std::string& name) : _name(name) {}
    ES::BasicEvent<int> event;

    void call(const void* sender) {
        std::cout << "Calling call" << std::endl;
    }
    void callInt(const void* sender, int* param) {
        std::cout << "Calling call with param:" << *param << std::endl;
    }
    void callOnlyInt(int param) {
        std::cout << "Name:" << _name << std::endl;
        std::cout << "Calling call without sender with param:" << param << std::endl;
    }

    void sendEvent(int num) {
        event.notify(num);
    }
private:
    std::string _name;
};

int main()
{
    std::cout << "Hello, world!" << std::endl;
    Obj* a = new Obj{};
    // ES::Delegate dl(a, &Obj::callInt);
    // int i = 10;
    // dl.notify(nullptr, &i);
    
    // ES::BaseDelegate baseDelegate(a, &Obj::callInt);
    // ES::AbstractDelegate<const void*, int*> *absDelegate = &baseDelegate;
    // absDelegate->notify(nullptr, &i);

    Obj observer1("foo");
    Obj observer2("bar");
    ES::BaseDelegate delegateObs1(&observer1, &Obj::callOnlyInt);
    ES::BaseDelegate delegateObs2(&observer2, &Obj::callOnlyInt);
    a->event += delegateObs1;
    a->event += delegateObs2;
    a->sendEvent(15);
    delete a;
    return 0;
}