class LFUCache {
private:
    int cap, minF;

    struct Info {
        int value, f;
        list<int>::iterator pos;
    };

    unordered_map<int, Info> cache;
    unordered_map<int, list<int>> freq;

public:
    LFUCache(int capacity) { this->cap = capacity; }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        freq[cache[key].f].erase(cache[key].pos);
        cache[key].f += 1;
        freq[cache[key].f].push_back(key);
        cache[key].pos = prev(freq[cache[key].f].end());

        minF += freq[minF].empty();
        return cache[key].value;
    }

    void put(int key, int value) {
        if (!cap)
            return;

        if (get(key) != -1) {
            cache[key].value = value;
            return;
        }

        if (cache.size() == cap) {
            cache.erase(freq[minF].front());
            freq[minF].pop_front();
        }

        freq[1].push_back(key);
        cache[key] = {value, 1, prev(freq[1].end())};
        minF = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */