#pragma GCC optimize(O3, "unroll-loops")

class MyHashSet {
private:
    bool set[1000001] = {0};
public:    
    void add(int key) {
        set[key] = 1;
    }
    
    void remove(int key) {
        set[key] = 0;
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