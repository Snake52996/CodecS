#include<hex_codec.hpp>
#include<iostream>
using CodecS::HexCodec;
using CodecS::Codec;
using namespace std;
int main(){
    const char* const v = "736e616B65";
    Codec* codec = new HexCodec();
    cout<<codec->decode(v);
    return 0;
}