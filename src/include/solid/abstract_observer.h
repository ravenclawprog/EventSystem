#ifndef ES_SOLID_ABSTRACT_OBSERVER_H
#define ES_SOLID_ABSTRACT_OBSERVER_H
#include "abstract_event_data.h"

namespace ES
{
    namespace solid
    {
        class AbstractObserver
        {
        public:
            virtual void call(AbstractEventData *eventData, void *sender) = 0;
            virtual ~AbstractObserver() {}
        };
    }   // namespace solid
}       // namespace ES

#endif // ES_SOLID_ABSTRACT_OBSERVER_H