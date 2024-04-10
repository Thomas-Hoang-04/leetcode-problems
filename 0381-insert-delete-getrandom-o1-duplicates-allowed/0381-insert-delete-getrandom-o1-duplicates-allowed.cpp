class RandomizedCollection {
private:
    unordered_map<int, vector<int>> mp;
    vector<pair<int, int>> nums;
    bool insert_state;
public:
    RandomizedCollection() {
        srand(time(0));
    }
    
    bool insert(int val) {
        insert_state = mp.find(val) == mp.end();       
        mp[val].push_back(nums.size());
        nums.push_back(make_pair(val, mp[val].size() - 1));
        return insert_state;
    }
    
    bool remove(int val) {
        unordered_map<int, vector<int>>::iterator t = mp.find(val);
        if (t == mp.end()) return false;
        nums[t->second.back()] = nums.back();
        mp[nums.back().first][nums.back().second] = t->second.back();

        nums.pop_back();
        t->second.pop_back();
        if (t->second.empty()) mp.erase(t);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */