class RandomizedSet {
private:
    unordered_map<int, int> mp;
    vector<int> nums;
public:
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        else {
            mp[val] = nums.size();
            nums.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        unordered_map<int, int>::iterator t = mp.find(val);
        if (t == mp.end()) return false;
        else {
            nums[t->second] = nums.back();
            mp[nums.back()] = t->second;
            nums.pop_back();
            mp.erase(t);
            return true;
        }
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */