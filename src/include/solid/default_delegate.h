#ifndef ES_SOLID_DEFAULT_DELEGATE_H
#define ES_SOLID_DEFAULT_DELEGATE_H
#include "abstract_event_data.h"
#include "interface_delegate.h"
#include "abstract_observer.h"
#include <iostream>
namespace ES
{
    namespace solid
    {
        class DefaultDelegate: public IDelegate
        {
        public:
            using ObserverClass = AbstractObserver;
            DefaultDelegate(ObserverClass* observerClass) : _observerClass(observerClass){
                std::cout << "Create default delegate" << std::endl;
            }
            DefaultDelegate(const DefaultDelegate &delegate)
            {
                std::cout << "Create default delegate" << std::endl;
                _observerClass = delegate._observerClass;
            }
            bool call(AbstractEventData *eventData, void *sender) override {
                if(_observerClass) {
                    (_observerClass->call)(eventData,sender);
                    return true;
                }
                return false;
            }
            virtual bool equal(const IDelegate& other) const override {
                const DefaultDelegate *pOther = dynamic_cast<const DefaultDelegate *>(other.unwrap());
                return pOther && _observerClass == pOther->_observerClass;
            }
            virtual IDelegate* clone() const override{
                return reinterpret_cast<IDelegate*>(new DefaultDelegate(*this));
            }
            virtual void disable() override {
                _observerClass = nullptr;
            }
            virtual ~DefaultDelegate() {
                std::cout << "Delete default delegate" << std::endl;
            }
        private:
            ObserverClass* _observerClass;
        };
    }   // namespace solid
}       // namespace ES
#endif // ES_SOLID_DEFAULT_DELEGATE_H