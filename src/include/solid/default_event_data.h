#ifndef ES_SOLID_DEFAULT_EVENT_DATA_H
#define ES_SOLID_DEFAULT_EVENT_DATA_H
#include "abstract_event_data.h"
#include <string>
namespace ES
{
    namespace solid
    {
        class DefaultEventData: public AbstractEventData
        {
        public:
            DefaultEventData(const std::string& data): AbstractEventData(), _data(data){}
            virtual ~DefaultEventData() {}
            std::string getString() {
                return _data;
            }
            void setString(const std::string& data) {
                _data = data;
            }
        private:
            std::string _data;
        };
    }   // namespace solid
}       // namespace ES

#endif // ES_SOLID_DEFAULT_EVENT_DATA_H