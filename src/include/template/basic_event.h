#ifndef ES_TEMPLATE_BASE_EVENT_H
#define ES_TEMPLATE_BASE_EVENT_H

#include "abstract_delegate.h"
#include "abstract_event.h"
#include "default_notification_policy.h"

namespace ES
{
    template <class ...TArgs>
    class BasicEvent : public AbstractEvent<DefaultNotificationPolicy<AbstractDelegate<TArgs...>, TArgs... >, AbstractDelegate<TArgs...>, TArgs...>
    {
    public:
        BasicEvent() {}

        ~BasicEvent() {}

    private:
        BasicEvent(const BasicEvent &e);
        BasicEvent &operator=(const BasicEvent &e);
    };
}

#endif // ES_BASE_EVENT_H