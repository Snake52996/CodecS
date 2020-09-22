#include<hex_codec.hpp>
using CodecS::Codec;
using CodecS::HexCodec;
HexCodec::HexCodec()noexcept{};
std::string HexCodec::encode(const char* const data, const unsigned int size)const{
    std::string result;
    for(unsigned int i = 0; i < size; ++i){
        result.push_back(FORWARD_TABLE(GET_HIGH_BYTE(data[i])));
        result.push_back(FORWARD_TABLE(GET_LOW_BYTE(data[i])));
    }
    return result;
}
std::string HexCodec::decode(const char* const data)const{
    std::string result;
    char temp;
    for(unsigned int i = 0; data[i] != '\0'; i += 2){
        SET_HIGH_BYTE(temp, RESERVE_TABLE(data[i]));
        SET_LOW_BYTE(temp, RESERVE_TABLE(data[i + 1]));
        result.push_back(temp);
    }
    return result;
}
std::string HexCodec::decode(const std::string& data)const{
    return this->decode(data.c_str());
}