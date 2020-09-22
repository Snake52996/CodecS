#include<codec_getter.hpp>
#include<iostream>
using namespace std;
int main(){
    cout<<CodecS::CodecGetter::getInstance("base64").encode("snake", 5)<<endl;
    cout<<CodecS::CodecGetter::getInstance("hex").encode("snake", 5)<<endl;
    cout<<CodecS::CodecGetter::getInstance("base64").encode("dragon", 6)<<endl;
    cout<<CodecS::CodecGetter::getInstance("hex").encode("dragon", 6)<<endl;
    cout<<CodecS::CodecGetter::getInstance("base64").encode("\x78\x69", 2)<<endl;
    cout<<CodecS::CodecGetter::getInstance("hex").encode("\x78\x69", 2)<<endl;
    return 0;
}