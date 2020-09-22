/**
 * @brief declaration of base64 coder/decoders
*/
_Pragma("once");
#include<codec.hpp>
namespace CodecS{
    class Base64Codec final: public Codec{
        private:
            static constexpr const char* const FORWARD_TABLE =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
            static inline unsigned int RESERVE_TABLE(const unsigned char& c){
		    	switch(c){
		    		case '=': return 0;
		    		case '+': return 62;
		    		case '/': return 63;
		    		default: break;
		    	}
		    	if(c >= 'A' && c <= 'Z') return c - 'A';
		    	if(c >= 'a' && c <= 'z') return c - 'a' + 26;
		    	if(c >= '0' && c <= '9') return c - '0' + 52;
		    	return 256; // never reaches here
		    }
            
        public:
            explicit Base64Codec()noexcept;
            ~Base64Codec() = default;
            std::string encode(const char* const, const unsigned int)const override;
            std::string decode(const char* const)const override;
            std::string decode(const std::string&)const override;
    };
}