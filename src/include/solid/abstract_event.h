#ifndef ES_TEMPLATE_ABSTRACT_EVENT_H
#define ES_TEMPLATE_ABSTRACT_EVENT_H
#include "interface_delegate.h"
#include "interface_notification_strategy.h"
#include "abstract_event_data.h"

namespace ES
{
    namespace solid 
    {
        class AbstractEvent
        {
        public:
    
            AbstractEvent() : _policy(nullptr), _enabled(true) {}
    
            AbstractEvent(INotificationStrategy* policy) : _policy(policy), _enabled(true)
            {
            }
    
            virtual ~AbstractEvent() {}
    
            void operator+=(const IDelegate &dl) {
                _policy->add(dl);
            }
    
            void operator-=(const IDelegate &dl) {
                _policy->remove(dl);
            }
    
            IDelegate* add(const IDelegate &dl) {
                return _policy->add(dl);
            }
    
            void remove(IDelegate dl) {
                _policy->remove(dl);
            }
    
            void operator()(AbstractEventData* eventData, void* sender) {
                notify(eventData, sender);
            }
    
            void notify(AbstractEventData* eventData, void* sender) {
                if (!_enabled)
                    return;
                _policy->notify(eventData, sender);
            }
    
            bool hasDelegates() const { 
                return !empty();
            }
    
            void enable() {
                _enabled = true;
            }
    
            void disable() {
                _enabled = false;
            }
    
            bool isEnabled() const {
                return _enabled;
            }
    
            void clear() {
                _policy->clear();
            }
    
            bool empty() const {
                return _policy->empty();
            }
    
        protected:
            INotificationStrategy* _policy;
            bool                   _enabled;
    
        private:
            AbstractEvent(const AbstractEvent &other);
            AbstractEvent &operator=(const AbstractEvent &other);
        };
    }
}
#endif // ES_ABSTRACT_EVENT_H