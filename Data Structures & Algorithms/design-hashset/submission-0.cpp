class MyHashSet {
public:
    vector<int> res;

    MyHashSet() : res(1e7 + 1, 0) {} 

    void add(int key) {
        res[key] = 1;
    }
    
    void remove(int key) {
        res[key] = 0;
    }
    
    bool contains(int key) {
        return res[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */