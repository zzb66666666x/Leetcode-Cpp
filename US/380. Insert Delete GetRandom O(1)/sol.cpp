// https://leetcode.com/problems/insert-delete-getrandom-o1/submissions/
class RandomizedSet {
public:
    unordered_map<int, int> m;
    vector<int> v;
    
    RandomizedSet() {}
    
    bool insert(int val) {
        if (m.count(val)==0){
            v.push_back(val);
            m[val] = v.size()-1;
            return true;
        }else{
            return false;
        }
    }
    
    bool remove(int val) {
        if (m.count(val)==0){
            return false;
        }else{
            int idx = m.find(val)->second;
            if (idx == v.size()-1){
                m.erase(val);
                v.pop_back();
            }else{
                int lastval = v[v.size()-1];
                v[idx] = lastval;
                m[lastval] = idx;
                v.pop_back();
                m.erase(val);
            }
            return true;
        }
    }
    
    int getRandom() {
        int idx = rand() % (v.size());
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
