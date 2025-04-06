#include <iostream>
#include "src/include/template/abstract_delegate.h"
#include "src/include/template/delegate.h"
#include "src/include/template/basic_event.h"

#include "src/include/solid/default_delegate.h"
#include "src/include/solid/default_event_data.h"
#include "src/include/solid/abstract_observer.h"
#include "src/include/solid/abstract_observer.h"
#include "src/include/solid/default_event.h"

struct objectSolid : public ES::solid::AbstractObserver
{
    ES::solid::DefaultEvent event;
    void call(ES::solid::AbstractEventData *eventData, void *sender) override
    {
        std::cout << "call of object solid" << std::endl;
    }
};
struct Obj
{
    Obj() : _name("default name") {}
    Obj(const std::string &name) : _name(name) {}
    ES::BasicEvent<int> event;

    void call(const void *sender)
    {
        std::cout << "Calling call" << std::endl;
    }
    void callInt(const void *sender, int *param)
    {
        std::cout << "Calling call with param:" << *param << std::endl;
    }
    void callOnlyInt(int param)
    {
        std::cout << "Name:" << _name << std::endl;
        std::cout << "Calling call without sender with param:" << param << std::endl;
    }

    void sendEvent(int num)
    {
        event.notify(num);
    }

private:
    std::string _name;
};

int main()
{
    {
        std::cout << "template example" << std::endl;
        Obj *a = new Obj{};
        ES::Delegate dl(a, &Obj::callInt);
        int i = 10;
        dl.notify(nullptr, &i);

        ES::BaseDelegate baseDelegate(a, &Obj::callInt);
        ES::AbstractDelegate<const void *, int *> *absDelegate = &baseDelegate;
        absDelegate->notify(nullptr, &i);

        Obj observer1("foo");
        Obj observer2("bar");
        ES::BaseDelegate delegateObs1(&observer1, &Obj::callOnlyInt);
        ES::BaseDelegate delegateObs2(&observer2, &Obj::callOnlyInt);
        a->event += std::move(ES::BaseDelegate(&observer1, &Obj::callOnlyInt));
        a->event += std::move(ES::BaseDelegate(&observer2, &Obj::callOnlyInt));
        a->event += delegateObs1;
        a->event += delegateObs2;
        a->sendEvent(15);
        delete a;
    }
    //
    {
        std::cout << "solid example" << std::endl;
        objectSolid *obj = new objectSolid();
        ES::solid::DefaultDelegate *dlg = new ES::solid::DefaultDelegate(obj);
        obj->event += dlg;
        obj->event.notify(nullptr, nullptr);
        delete obj;
    }
    return 0;
}