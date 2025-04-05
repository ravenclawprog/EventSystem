#ifndef ES_SOLID_DEFAULT_DELEGATE_H
#define ES_SOLID_DEFAULT_DELEGATE_H
#include "abstract_event_data.h"
#include "interface_delegate.h"
#include "abstract_observer.h"
namespace ES
{
    namespace solid
    {
        class DefaultDelegate: public IDelegate
        {
        public:
            using ObserverClass = AbstractObserver;
            using CallMethod = void (ObserverClass::*)(AbstractEventData *eventData, void *sender);
            DefaultDelegate(ObserverClass* observerClass, CallMethod method) : _observerClass(observerClass), _method(method){
            }
            DefaultDelegate(const DefaultDelegate &delegate)
            {
                _observerClass = delegate._observerClass;
                _method = delegate._method;
            }
            bool call(AbstractEventData *eventData, void *sender) override {
                if(_observerClass) {
                    (_observerClass->*_method)(eventData,sender);
                    return true;
                }
                return false;
            }
            virtual bool equal(const IDelegate& other) const override {
                const DefaultDelegate *pOther = dynamic_cast<const DefaultDelegate *>(other.unwrap());
                return pOther && _observerClass == pOther->_observerClass && _method == pOther->_method;
            }
            virtual IDelegate* clone() const override{
                return reinterpret_cast<IDelegate*>(new DefaultDelegate(*this));
            }
            virtual void disable() override {
                _observerClass = nullptr;
            }
            virtual ~DefaultDelegate() {}
        private:
            ObserverClass* _observerClass;
            CallMethod _method;
        };
    }   // namespace solid
}       // namespace ES
#endif // ES_SOLID_DEFAULT_DELEGATE_H