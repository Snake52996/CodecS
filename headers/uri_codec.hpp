/**
 * @brief declaration of uri coder/decoders
*/
_Pragma("once");
#include<codec.hpp>
namespace CodecS{
    class UriCodec final: public Codec{
        private:
            static inline char toHex(const unsigned int& val)noexcept{
                return val > 9 ? val - 10 + 'a' : val + '0';
            }
            static inline char fromHex(const char& c)noexcept{
                if(c >= '0' && c <= '9') return c - '0';
                if(c >= 'a' && c <= 'f') return c - 'a' + 10;
                return c - 'A' + 10;
            }
        public:
            explicit UriCodec()noexcept;
            ~UriCodec() = default;
            std::string encode(const char* const, const unsigned int)const override;
            std::string decode(const char* const)const override;
            std::string decode(const std::string&)const override;
    };
}