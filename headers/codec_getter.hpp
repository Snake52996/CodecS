_Pragma("once");
#include<codec.hpp>
#include<base64_codec.hpp>
#include<hex_codec.hpp>
#include<map>
#include<string>
#include<memory>
#include<stdexcept>
using std::map;
using std::string;
using std::unique_ptr;
using std::make_unique;
namespace CodecS{
    class CodecGetter final{
        public:
            CodecGetter() = delete;
            static inline Codec& getInstance(const string& codec_name){
                static map<string, unique_ptr<Codec>> instance_map_;
                if(!instance_map_.count(codec_name)){
                    if(codec_name == "base64")
                        instance_map_[codec_name] = make_unique<Base64Codec>();
                    else if(codec_name == "hex")
                        instance_map_[codec_name] = make_unique<HexCodec>();
                    else throw std::runtime_error("unknown codec");
                }
                return *instance_map_[codec_name];
            }
    };
}
