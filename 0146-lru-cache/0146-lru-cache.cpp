class LRUCache {
    int cap;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> k;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        k.erase(cache[key].second);
        k.push_front(key);
        cache[key].second = k.begin();

        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (!cap) return;

        if (get(key) != -1) {
            cache[key].first = value;
            return;
        }

        if (cache.size() == cap) {
            cache.erase(k.back());
            k.pop_back();
        }

        k.push_front(key);
        cache[key] = {value, k.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */