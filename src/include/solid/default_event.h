#ifndef ES_SOLID_DEFAULT_EVENT_H
#define ES_SOLID_DEFAULT_EVENT_H
#include "abstract_event.h"
#include "default_notification_strategy.h"
namespace ES
{
    namespace solid 
    {
        class DefaultEvent: public AbstractEvent
        {
        public:
    
            DefaultEvent() : AbstractEvent(new DefaultNotificationStrategy()) {}
    
            virtual ~DefaultEvent() {}
        };
    }
}
#endif // ES_SOLID_DEFAULT_EVENT_H