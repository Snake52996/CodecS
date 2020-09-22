#include<base64_codec.hpp>
#include<iostream>
using CodecS::Base64Codec;
using CodecS::Codec;
using namespace std;
int main(){
    const char* const v = "c25ha2U=";
    Codec* codec = new Base64Codec();
    cout<<codec->decode(v);
    return 0;
}