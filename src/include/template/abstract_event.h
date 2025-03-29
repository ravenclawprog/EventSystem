#ifndef ES_TEMPLATE_ABSTRACT_EVENT_H
#define ES_TEMPLATE_ABSTRACT_EVENT_H

namespace ES
{
    template <class TRealizationStrategy, class TDelegate, class... TArgs>
    class AbstractEvent
    {
    public:
        using DelegateHandle = TDelegate *;

        AbstractEvent() : _policy(), _enabled(true) {}

        AbstractEvent(const TRealizationStrategy &policy) : _policy(policy), _enabled(true)
        {
        }

        virtual ~AbstractEvent() {}

        void operator+=(const TDelegate &dl) {
            _policy.add(dl);
        }

        void operator-=(const TDelegate &dl) {
            _policy.remove(dl);
        }

        DelegateHandle add(const TDelegate &dl) {
            return _policy.add(dl);
        }

        void remove(DelegateHandle dl) {
            _policy.remove(dl);
        }

        void operator()(TArgs ...args) {
            notify(args...);
        }

        void notify(TArgs ...args) {
            if (!_enabled)
                return;
            // TRealizationStrategy policy(_policy);
            _policy.notify(args...);
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
            _policy.clear();
        }

        bool empty() const {
            return _policy.empty();
        }

    protected:
        TRealizationStrategy _policy;
        bool                 _enabled;

    private:
        AbstractEvent(const AbstractEvent &other);
        AbstractEvent &operator=(const AbstractEvent &other);
    };
}
#endif // ES_ABSTRACT_EVENT_H