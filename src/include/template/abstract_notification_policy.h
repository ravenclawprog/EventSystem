#ifndef ES_TEMPLATE_ABSTRACT_NOTIFICATION_POLICY_H
#define ES_TEMPLATE_ABSTRACT_NOTIFICATION_POLICY_H

namespace ES {
    template <class TDelegate, class ...TArgs>
    class AbstractNotificationPolicy {
    public:
        using DelegateHandle = TDelegate*;
    
        AbstractNotificationPolicy() {}
    
        virtual ~AbstractNotificationPolicy() { }
    
        virtual void notify(TArgs ...arguments) = 0;
    
        virtual DelegateHandle add(const TDelegate &delegate) = 0;
    
        virtual void remove(const TDelegate &delegate) = 0;
    
        virtual void remove(DelegateHandle delegateHandle) = 0;
    
        virtual void clear() = 0;

        virtual bool empty() const = 0;
    };
}

#endif // ES_TEMPLATE_ABSTRACT_NOTIFICATION_POLICY_H