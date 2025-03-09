#include <iostream>
#include <map>
#include <list>

class LRUCache{
    public:

    LRUCache(int size){
        m_size = size;
    }

    void put(int key, int value){
        if(track.size() >= m_size){
            std::cout << "remove " << track.back() << std::endl;
            cache.erase(track.back());
            track.pop_back();
        }

        if(cache.find(key) != cache.end())
        {
            moveToFront(key);
            cache[key].first = value;
        }
        else{
            std::cout << "add " << key << std::endl;
            track.push_front(key);
            cache[key] = {value,track.begin()};
        }
    }

    int get(int key){
        if(cache.find(key) != cache.end()){
            auto ret = cache[key].first;
            moveToFront(key);
            return ret;
        }
        return -1;
    }

    private:

    std::map<int,std::pair<int,std::list<int>::iterator>> cache; // key -> value, index in list
    std::list<int> track; //index -> key

    int m_size = 0;

    void moveToFront(int key){
        std::cout << "move to front " << key << std::endl;
        track.erase(cache[key].second);
        track.push_front(key);
        cache[key].second = track.begin();
    }

};

int main(){

    LRUCache Cache(2);
    Cache.put(1, 1);
    Cache.put(2, 2);
    Cache.get(1);
    Cache.put(3, 3);
    Cache.get(2);
}