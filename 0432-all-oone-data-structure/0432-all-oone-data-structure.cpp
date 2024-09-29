#pragma GCC optimize(O3, "unroll-loops")

typedef pair<int, int> p2;

class AllOne {
private:
    vector<vector<string>> store;
    unordered_map<string, p2> mp;
public:
    AllOne() : store(2, vector<string>()) {}

    void delKey(int freq, int loc) {
        if (store[freq].size() == 1) {
            store[freq].pop_back();
            return;
        }
        string temp = store[freq][loc];
        store[freq][loc] = store[freq].back();
        store[freq].pop_back();
        mp[store[freq].back()].second = loc;
    }
    
    void inc(string key) {
        if (mp.find(key) == mp.end()) {
            mp[key] = { 1, store[1].size() };
            store[1].push_back(key);
        } else {
            auto [freq, loc] = mp[key];
            delKey(freq, loc);
            if (freq + 1 == store.size()) {
                mp[key] = { freq + 1, 0 };
                store.push_back({ key });
            } else {
                mp[key] = { freq + 1, store[freq + 1].size() };
                store[freq + 1].push_back(key);
            }
        }
    }
    
    void dec(string key) {
        if (mp.find(key) == mp.end()) 
            return;
        else {
            auto [freq, loc] = mp[key];
            delKey(freq, loc);
            if (freq == 1) mp.erase(key);
            else {
                mp[key] = { freq - 1, store[freq - 1].size() };
                store[freq - 1].push_back(key);
            }
        }
    }
    
    string getMaxKey() {
        for (int i = store.size() - 1; i > 0; i--) {
            if (store[i].empty()) continue;
            else return store[i][0];
        }
        return "";
    }
    
    string getMinKey() {
        for (vector<string>& buck: store) {
            if (buck.empty()) continue;
            else return buck[0];
        }
        return "";
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */