#ifndef ES_SOLID_INOTIFICATION_STRATEGY_H
#define ES_SOLID_INOTIFICATION_STRATEGY_H
#include "interface_delegate.h"
#include "abstract_event_data.h"

namespace ES
{
    namespace solid
    {
        class INotificationStrategy
        {
        public:
            virtual void notify(AbstractEventData *eventData, void *sender) = 0;

            virtual IDelegate *add(const IDelegate &delegate) = 0;

            virtual IDelegate *add(IDelegate* delegate) = 0;

            virtual void remove(const IDelegate &delegate) = 0;

            virtual void clear() = 0;

            virtual bool empty() const = 0;

            virtual ~INotificationStrategy() {}
        };
    }   // namespace solid
}       // namespace ES
#endif // ES_SOLID_INOTIFICATION_STRATEGY_H