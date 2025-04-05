#ifndef ES_TEMPLATE_DEFAULT_NOTIFICATION_POLICY
#define ES_TEMPLATE_DEFAULT_NOTIFICATION_POLICY
#include "abstract_notification_policy.h"

#include <vector>
#include <memory>

namespace ES {

template <class TDelegate, class ...TArgs>
class DefaultNotificationPolicy : public AbstractNotificationPolicy<TDelegate, TArgs...>
{
public:
    using  DelegateHandle = TDelegate *;
    using  DelegatePtr = std::shared_ptr<TDelegate>;
    using  DelegatesContainer = std::vector<DelegatePtr>;
    using  Iterator = typename DelegatesContainer::iterator;

public:
    DefaultNotificationPolicy() {}

    DefaultNotificationPolicy(const DefaultNotificationPolicy &s) : _delegates(s._delegates) { }

    ~DefaultNotificationPolicy() {}

    void notify(TArgs ...arguments)
    {
        for (Iterator it = _delegates.begin(); it != _delegates.end(); ++it)
        {
            (*it)->notify(arguments...);
        }
    }

    DelegateHandle add(const TDelegate & delegate)
    {
        DelegatePtr pdl = DelegatePtr(delegate.clone());
        _delegates.push_back(pdl);
        return pdl.get();
    }

    void remove(const TDelegate & delegate)
    {
        for (Iterator it = _delegates.begin(); it != _delegates.end(); ++it)
        {
            if (delegate.equal(**it))
            {
                (*it)->disable();
                _delegates.erase(it);
                return;
            }
        }
    }

    void remove(DelegateHandle dlPtr)
    {
        for (Iterator it = _delegates.begin(); it != _delegates.end(); ++it)
        {
            if ((*it) == DelegatePtr(dlPtr))
            {
                (*it)->disable();
                _delegates.erase(it);
                return;
            }
        }
    }

    DefaultNotificationPolicy & operator=(const DefaultNotificationPolicy & s)
    {
        if (this != &s)
        {
            _delegates = s._delegates;
        }
        return *this;
    }

    void clear()
    {
        for (Iterator it = _delegates.begin(); it != _delegates.end(); ++it)
        {
            (*it)->disable();
        }
        _delegates.clear();
    }

    bool empty() const { return _delegates.empty(); }

protected:
    DelegatesContainer _delegates;
};

} // namespace ES
#endif // ES_TEMPLATE_DEFAULT_NOTIFICATION_POLICY