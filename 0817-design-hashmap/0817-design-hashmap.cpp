class MyHashMap {
public:
    vector<int> v = vector<int>(1000001, -1);
    MyHashMap() {

    }
    
    void put(int key, int value) {
        v[key] = value;
    }
    
    int get(int key) {
        if(v[key] == -1) return -1;
        return v[key];
    }
    
    void remove(int key) {
        v[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */