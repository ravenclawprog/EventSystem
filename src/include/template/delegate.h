#ifndef ES_TEMPLATE_DELEGATE_H
#define ES_TEMPLATE_DELEGATE_H
#include "abstract_delegate.h"

#include <iostream>
#include <type_traits>

namespace ES
{

    template <class TClass, class TReturn, class... TArgs>
    class Delegate
    {
    public:
        using CallMethod = TReturn (TClass::*)(const void *, TArgs...);
        Delegate(const Delegate &delegate)
        {
            std::cout << "Delegate is created!" << std::endl;
            _callObject = delegate._callObject;
            _callMethod = delegate._callMethod;
        }
        Delegate(TClass *obj, CallMethod method)
        {
            std::cout << "Delegate is created!" << std::endl;
            _callObject = obj;
            _callMethod = method;
        }
        ~Delegate()
        {
            std::cout << "Delegate is deleted!" << std::endl;
        }
        Delegate &operator=(const Delegate &delegate)
        {
            if (&delegate != this)
            {
                this->_callObject = delegate._callObject;
                this->_callMethod = delegate._callMethod;
            }
            return *this;
        }
        bool operator==(const Delegate &other)
        {
            Delegate *pOther = &other;
            return pOther && _callObject == pOther->_callObject && _callMethod == pOther->_callMethod;
        }
        void disable()
        {
            _callObject = nullptr;
        }
        TReturn notify(const void *sender, TArgs... arguments)
        {
            if (_callObject)
            {
                return (_callObject->*_callMethod)(sender, std::forward<TArgs>(arguments)...);
            }
            return TReturn{};
        }

    protected:
        TClass *_callObject;
        CallMethod _callMethod;

    private:
        Delegate();
    };
    template <class TClass, class... TArgs>
    class BaseDelegate : public AbstractDelegate<TArgs...>
    {
    public:
        using CallMethod = void (TClass::*)(TArgs...);
        BaseDelegate(const BaseDelegate &delegate) : AbstractDelegate<TArgs...>(delegate)
        {
            std::cout << "Delegate is created!" << std::endl;
            _callObject = delegate._callObject;
            _callMethod = delegate._callMethod;
        }
        BaseDelegate(TClass *obj, CallMethod method) : AbstractDelegate<TArgs...>()
        {
            std::cout << "Delegate is created!" << std::endl;
            _callObject = obj;
            _callMethod = method;
        }
        ~BaseDelegate()
        {
            std::cout << "Delegate is deleted!" << std::endl;
        }
        BaseDelegate &operator=(const BaseDelegate &delegate)
        {
            if (&delegate != this)
            {
                this->_callObject = delegate._callObject;
                this->_callMethod = delegate._callMethod;
            }
            return *this;
        }
        bool equal(const AbstractDelegate<TArgs...> &other) const override
        {
            const BaseDelegate *pOther = dynamic_cast<const BaseDelegate *>(other.unwrap());
            return pOther && _callObject == pOther->_callObject && _callMethod == pOther->_callMethod;
        }
        void disable() override
        {
            _callObject = nullptr;
        }
        bool notify(TArgs... arguments) override
        {
            if (_callObject)
            {
                (_callObject->*_callMethod)(arguments...);
                return true;
            }
            return false;
        }
        AbstractDelegate<TArgs...> *clone() const override
        {
            return new BaseDelegate(*this);
        }

    protected:
        TClass *_callObject;
        CallMethod _callMethod;

    private:
        BaseDelegate();
    };
} // namespace ES
#endif // ES_TEMPLATE_DELEGATE_H