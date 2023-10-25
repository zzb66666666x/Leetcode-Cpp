class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        unordered_map<int, vector<int>> g;
        int ret = *max_element(vals.begin(), vals.end());
        for (auto& e : edges){
            int ev0 = vals[e[0]];
            int ev1 = vals[e[1]];
            if (ev0 > 0){
                g[e[1]].push_back(ev0);
            }
            if (ev1 > 0){
                g[e[0]].push_back(ev1);
            }
        }
        for (auto& [key, vec] : g){
            sort(vec.begin(), vec.end(), [](int a, int b){return a>b;});
            int sval = vals[key];
            int maxidx = min(k, (int)vec.size());
            for (int i=0; i < maxidx; i++){
                sval += vec[i];
            }
            ret = max(ret, sval);
        }
        return ret;
    }
};
