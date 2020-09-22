#include<base64_codec.hpp>
using CodecS::Codec;
using CodecS::Base64Codec;
Base64Codec::Base64Codec()noexcept{};
std::string Base64Codec::encode(const char* const data, const unsigned int size)const{
    std::string result;
    unsigned int rare = size - size % 3;
    for(unsigned int i = 0; i < rare; i += 3){
        result.push_back(FORWARD_TABLE[data[i] >> 2]);
        result.push_back(FORWARD_TABLE[((data[i] & 3) << 4) | (data[i + 1] >> 4)]);
        result.push_back(FORWARD_TABLE[((data[i + 1] & 15) << 2) | (data[i + 2] >> 6)]);
        result.push_back(FORWARD_TABLE[data[i + 2] & 63]);
    }
    switch(size - rare){
        case 1:
            result.push_back(FORWARD_TABLE[data[rare] >> 2]);
            result.push_back(FORWARD_TABLE[((data[rare] & 3) << 4) | 0]);
            result.push_back('=');
            result.push_back('=');
            break;
        case 2:
            result.push_back(FORWARD_TABLE[data[rare] >> 2]);
            result.push_back(FORWARD_TABLE[
                ((data[rare] & 3) << 4) | (data[rare + 1] >> 4)
            ]);
            result.push_back(FORWARD_TABLE[((data[rare + 1] & 15) << 2) | 0]);
            result.push_back('=');
            break;
        default: break;
    }
    return result;
}
std::string Base64Codec::decode(const char* const data)const{
    std::string result;
    unsigned int i;
    for(i = 0; data[i] != '\0'; i += 4){
        result.push_back(
            (RESERVE_TABLE(data[i]) << 2) | (RESERVE_TABLE(data[i + 1]) >> 4)
        );
		result.push_back(
            ((RESERVE_TABLE(data[i + 1]) & 15) << 4) | (RESERVE_TABLE(data[i + 2]) >> 2)
        );
		result.push_back(
            ((RESERVE_TABLE(data[i + 2]) & 3) << 6) | RESERVE_TABLE(data[i + 3])
        );
    }
    if(data[i - 1] == '=') result.pop_back();
    if(data[i - 2] == '=') result.pop_back();
    return result;
}
std::string Base64Codec::decode(const std::string& data)const{
    return this->decode(data.c_str());
}