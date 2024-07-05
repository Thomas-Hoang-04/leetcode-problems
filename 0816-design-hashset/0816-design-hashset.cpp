#pragma GCC optimize(O3, "unroll-loops");

class MyHashSet {
private:
    array<bool, 1000001> set;
public:
    MyHashSet() {
        set.fill(false);
    }
    
    void add(int key) {
        set[key] = true;
    }
    
    void remove(int key) {
        set[key] = false;
    }
    
    bool contains(int key) {
        return set[key];
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */