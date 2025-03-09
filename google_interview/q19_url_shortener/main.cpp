#include <functional>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <string>
#include <random>
#include <ctime>
#include <map>


using url_pair = std::pair<std::string,std::string>;
std::map<int, url_pair> long2short;
std::map<int, url_pair> short2long;

std::string getUUID()
{
    srand(std::time(nullptr));
    unsigned long long id = std::rand() % static_cast<unsigned long long>(10E15);
    std::hash<int> hash;

    std::ostringstream oss;
    oss << std::hex << std::setw(16) << std::setfill('0') << hash(id);
    std::string uuid = oss.str();

    return uuid;
}

std::string addLong(std::string long_url){
    std::string base_url = "https://shortly.com/";
    int i = 0;

    std::hash<std::string> hash;
    int long_hash = hash(long_url);
    std::string uuid = getUUID();

    if(long2short.find(long_hash) != long2short.end())
    {
        if(long2short[long_hash].first == long_url)
        {
            return long2short[long_hash].second;
        }
        else
        {
            return "COLLISION";
        }
    }
    else{
        url_pair urls = {long_url, base_url+uuid};

        int short_hash = hash(base_url+uuid);
        short2long[short_hash] = urls;
        long2short[long_hash] = urls;
        return long2short[long_hash].second;
    }
}

std::string getShort2Long(std::string short_url){

    std::hash<std::string> hash;
    int short_hash = hash(short_url);
    std::string uuid = getUUID();

    if(short2long.find(short_hash) != short2long.end())
    {
        return short2long[short_hash].first;
    }
    else{
        return "None";
    }
}

//chat gpt
std::string generate_random_string(size_t length) {
    // Define the characters that can appear in the random string
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    // Random engine (we'll use a random device to seed a Mersenne Twister engine)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, characters.size() - 1);
    std::string random_str;
    // Generate random characters
    for (size_t i = 0; i < length; ++i) {
        random_str += characters[dis(gen)];  // Pick a random character from 'characters'
    }
    return random_str;
}

int main(){
    for(int n = 0 ; n < 10000; n++)
    {
        std::string long_url = "https://long_url.com/dwad/dwadwa/dw/ad/wa/"+generate_random_string(16)+"/target";
        if(addLong(long_url) == "COLLISION") break;
        std::cout << addLong(long_url) << std::endl;
        std::cout << getShort2Long(addLong(long_url)) << std::endl;
    }
    return 0;
}