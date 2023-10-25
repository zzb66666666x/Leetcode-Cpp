class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> m;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end())
            return "";
        auto& v = m[key];
        if (v.size() == 0)
            return "";
        auto it = upper_bound(v.begin(), v.end(), timestamp, [](auto& a, auto& b){
            return a < b.first;
        });
        if (it == v.begin()){
            return "";
        }
        it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
