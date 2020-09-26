#include<uri_codec.hpp>
#include<cctype>
using CodecS::Codec;
using CodecS::UriCodec;
using std::isalnum;
UriCodec::UriCodec()noexcept{};
std::string UriCodec::encode(const char* const data, const unsigned int size)const{
    std::string result;
    char temp;
    for(unsigned int i = 0; i < size; ++i){
        temp = data[i];
        if(
            isalnum(static_cast<unsigned char>(temp)) ||
            temp == '-' || temp == '_' || temp == '.' || temp == '~' ||
            temp == '+' || temp == ':' || temp == ';' || temp == '!' ||
            temp == '@' || temp == '#' || temp == '$' || temp == '&' ||
            temp == '*' || temp == '(' || temp == ')' || temp == '=' ||
            temp == '?' || temp == '/' || temp == ',' || temp == '\''
        ) result.push_back(temp);
        else{
            result.push_back('%');
            result.push_back(toHex(temp >> 4));
            result.push_back(toHex(temp & 15));
        }
    }
    return result;
}
std::string UriCodec::decode(const char* const data)const{
    std::string result;
    for(unsigned int i = 0; data[i] != '\0'; i += 4){
        if(data[i] == '%'){
            result.push_back(static_cast<char>(
                (fromHex(data[i + 1]) << 4) | fromHex(data[i + 2])
            ));
            i += 2;
        }else result.push_back(data[i]);
    }
    return result;
}
std::string UriCodec::decode(const std::string& data)const{
    return this->decode(data.c_str());
}