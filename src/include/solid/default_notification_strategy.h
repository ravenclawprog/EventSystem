#ifndef ES_SOLID_DEFAULT_NOTIFICATION_STRATEGY_H
#define ES_SOLID_DEFAULT_NOTIFICATION_STRATEGY_H
#include "interface_notification_strategy.h"
#include "interface_delegate.h"
#include <vector>
#include <memory>

namespace ES
{
    namespace solid
    {
        class DefaultNotificationStrategy : public INotificationStrategy
        {
        public:
            using DelegatePtr = std::shared_ptr<IDelegate>;
            using DelegateContainer = std::vector<DelegatePtr>;
            using Iterator = DelegateContainer::iterator;

            virtual void notify(AbstractEventData *eventData, void *sender) override
            {
                for (Iterator it = _delegates.begin(); it != _delegates.end(); ++it)
                {
                    (*it)->call(eventData, sender);
                }
            }

            virtual IDelegate *add(const IDelegate &delegate) override
            {
                DelegatePtr pdl = DelegatePtr(delegate.clone());
                _delegates.push_back(pdl);
                return pdl.get();
            }
            virtual IDelegate *add(IDelegate* delegate) override
            {
                DelegatePtr pdl = DelegatePtr(delegate);
                _delegates.push_back(pdl);
                return pdl.get();
            }

            virtual void remove(const IDelegate &delegate) override
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

            virtual void clear() override
            {
                for (Iterator it = _delegates.begin(); it != _delegates.end(); ++it)
                {
                    (*it)->disable();
                }
                _delegates.clear();
            }

            virtual bool empty() const override
            {
                return _delegates.empty();
            }
            virtual ~DefaultNotificationStrategy() {}

        protected:
            DelegateContainer _delegates;
        };
    } // namespace solid
} // namespace ES
#endif // ES_SOLID_DEFAULT_NOTIFICATION_STRATEGY_H