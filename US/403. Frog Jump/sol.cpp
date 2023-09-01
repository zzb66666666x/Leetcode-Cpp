class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, bool> m;
        unordered_map<int, int> pos2idx;
        if (stones.size()==2 && stones[1] == 1)
            return true;
        if (stones[1] != 1)
            return false;
        for(int i = 0; i < stones.size(); i++) pos2idx[stones[i]] = i;
        return jump(stones, 1, 1, m, pos2idx);
    }

    bool jump(vector<int>& stones, int k, int idx, unordered_map<int, bool>& m, unordered_map<int, int>& pos2idx){
        // cout<<"jump to idx="<<idx<<" with k="<<k<<" and pos="<<stones[idx]<<endl;
        int key = 10000*idx + k;
        if (m.find(key) != m.end()){
            // cout<<"cache hit"<<endl;
            return false;
        }
        int pos = stones[idx];
        int steps[] = {k-1, k, k+1};
        bool ret = false;
        for (int i=0; i<3; i++){
            // cout<<"steps="<<steps[i]<<" k="<<k<<endl;
            if (steps[i] == 0)
                continue;
            int nextpos = pos + steps[i];
            // cout<<nextpos<<endl;
            if (nextpos > stones[stones.size()-1]){
                ret |= false;
                continue;
            }else if (nextpos == stones[stones.size()-1]){
                return true;
            }
            if (pos2idx.find(nextpos) == pos2idx.end()){
                ret |= false;
                continue;
            }
            int nextidx = pos2idx[nextpos];
            ret |= jump(stones, steps[i], nextidx, m, pos2idx);
            if (ret){
                return true;
            }
        }
        if (!ret)
            m[10000*idx + k] = false;
        return ret;
    }
};
