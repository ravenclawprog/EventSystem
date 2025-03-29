#ifndef ES_ABSTRACT_DELEGATE_H
#define ES_ABSTRACT_DELEGATE_H

namespace ES
{

    template <class... TArgs>
    class AbstractDelegate
    {
    public:
        AbstractDelegate() {}
        AbstractDelegate(const AbstractDelegate &other) {}
        virtual ~AbstractDelegate() {}
        virtual bool equal(const AbstractDelegate &other) const = 0;
        virtual void disable() = 0;
        virtual bool notify(TArgs... arguments) = 0;
        virtual AbstractDelegate *clone() const = 0;
        virtual const AbstractDelegate *unwrap() const
        {
            return this;
        }
        virtual AbstractDelegate *unwrap()
        {
            return this;
        }
    };
}
#endif // ES_ABSTRACT_DELEGATE_H