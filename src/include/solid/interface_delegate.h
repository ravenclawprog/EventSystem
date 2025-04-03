#ifndef ES_SOLID_IDELEGATE_H
#define ES_SOLID_IDELEGATE_H
#include "abstract_event_data.h"
namespace ES
{
    namespace solid
    {
        class IDelegate
        {
        public:
            virtual void call(AbstractEventData *eventData, IDelegate *sender) = 0;
            virtual ~IDelegate() {}
        };
    }   // namespace solid
}       // namespace ES
#endif // ES_SOLID_IDELEGATE_H