#ifndef ES_DELEGATE_H
#define ES_DELEGATE_H
namespace ES
{

    template <class TClass, class... TArgs>
    class Delegate
    {
    public:
        typedef void (TClass::*NotifyMethod)(const void *, TArgs ...);

        Delegate(const Delegate &delegate);
        Delegate(TClass *obj, NotifyMethod method);
        ~Delegate();
        Delegate &operator=(const Delegate &delegate);
        void disable();
        bool isEqual(const Delegate &other);
        Delegate *unwrap();
        bool notify(const void *, TArgs...arguments);

    protected:
        TClass *_receiveObject;
        NotifyMethod _receiveMethod;

    private:
        Delegate();
    };
    template <class TClass, class... TArgs>
    Delegate<TClass, TArgs...>::Delegate(const Delegate &delegate)
    {
        std::cout << "Delegate is created!" << std::endl;
    }
    template <class TClass, class... TArgs>
    Delegate<TClass, TArgs...>::Delegate(TClass *obj, NotifyMethod method) : _receiveObject(obj), _receiveMethod(method)
    {
    }
    template <class TClass, class... TArgs>
    Delegate<TClass, TArgs...>::~Delegate()
    {
        std::cout << "Delegate is deleted!" << std::endl;
    }
    template <class TClass, class... TArgs>
    Delegate<TClass, TArgs...> &Delegate<TClass, TArgs...>::operator=(const Delegate &delegate)
    {
        if (&delegate != this)
        {
            this->_receiveObject = delegate._receiveObject;
            this->_receiveMethod = delegate._receiveMethod;
        }
        return *this;
    }
    template <class TClass, class... TArgs>
    void Delegate<TClass, TArgs...>::disable()
    {
        _receiveObject = nullptr;
    }

    template <class TClass, class... TArgs>
    bool Delegate<TClass, TArgs...>::notify(const void *sender, TArgs ...arguments)
    {
        if (_receiveObject)
        {
            (_receiveObject->*_receiveMethod)(sender, arguments...);
            return true;
        }
        else
            return false;
    }

    template <class TClass, class... TArgs>
    bool Delegate<TClass, TArgs...>::isEqual(const Delegate &other)
    {
        Delegate *pOther = dynamic_cast<Delegate *>(other.unwrap());
        return pOther && _receiveObject == pOther->_receiveObject && _receiveMethod == pOther->_receiveMethod;
    }
    template <class TClass, class... TArgs>
    Delegate<TClass, TArgs...> *Delegate<TClass, TArgs...>::unwrap()
    {
        return this;
    }

} // namespace ES
#endif // ES_DELEGATE_H