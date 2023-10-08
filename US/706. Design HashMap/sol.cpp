class MyHashMap {
private:
    int base = 769;
    vector<list<pair<int, int>>> data;
    int hash(int key){
        return key % base;
    }
public:
    MyHashMap(): data(base){}
    
    void put(int key, int value) {
        int idx = hash(key);
        for (auto it=data[idx].begin(); it != data[idx].end(); it++){
            if (it->first == key){
                it->second = value;
                return;
            }
        }
        data[idx].push_back(make_pair(key, value));
    }
    
    int get(int key) {
        int idx = hash(key);
        for (auto it=data[idx].begin(); it != data[idx].end(); it++){
            if (it->first == key){
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);
        for (auto it=data[idx].begin(); it != data[idx].end(); it++){
            if (it->first == key){
                data[idx].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
