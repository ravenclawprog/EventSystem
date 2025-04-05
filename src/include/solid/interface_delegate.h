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
            virtual bool call(AbstractEventData *eventData, void *sender) = 0;
            virtual bool equal(const IDelegate& other) const = 0;
            virtual IDelegate *clone() const = 0;
            virtual void disable() = 0;
            virtual const IDelegate *unwrap() const
            {
                return this;
            }
            virtual IDelegate *unwrap()
            {
                return this;
            }
            virtual ~IDelegate() {}
        };
    }   // namespace solid
}       // namespace ES
#endif // ES_SOLID_IDELEGATE_H