/**
 * @brief declaration of base class to coder/decoders
*/
_Pragma("once");
#include<string>
namespace CodecS{
    class Codec{
        protected:
            explicit Codec() = default;
        public:
            virtual ~Codec() = default;
            virtual std::string encode(const char* const, const unsigned int)const = 0;
            virtual std::string decode(const char* const)const = 0;
            virtual std::string decode(const std::string&)const = 0;
    };
}