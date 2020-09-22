/**
 * @brief declaration of hex coder/decoders
*/
_Pragma("once");
#include<codec.hpp>
namespace CodecS{
    class HexCodec final: public Codec{
        private:
            static inline char FORWARD_TABLE(const unsigned int& val){
                if(val < 10) return val + '0';
                return val - 10 + 'A';
            }
            static inline unsigned int RESERVE_TABLE(const char& c){
		    	if(c >= 'A' && c <= 'Z') return c - 'A' + 10;
		    	if(c >= 'a' && c <= 'z') return c - 'a' + 10;
		    	if(c >= '0' && c <= '9') return c - '0';
		    	return 256; // never reaches here
		    }
            static inline unsigned int GET_HIGH_BYTE(char c){
                return c >> 4;
            }
            static inline unsigned int GET_LOW_BYTE(char c){
                return c & 0x0f;
            }
            static inline void SET_HIGH_BYTE(char& c, unsigned int val){
                c = (c & 0x0f) | (val << 4);
            }
            static inline void SET_LOW_BYTE(char& c, unsigned int val){
                c = (c & 0xf0) | val;
            }
        public:
            explicit HexCodec()noexcept;
            ~HexCodec() = default;
            std::string encode(const char* const, const unsigned int)const override;
            std::string decode(const char* const)const override;
            std::string decode(const std::string&)const override;
    };
}