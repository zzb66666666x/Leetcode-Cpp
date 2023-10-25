class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 1){
            return move(vector<int>{0, 1});
        }
        if (n == 2){
            return move(vector<int>{0, 1, 3, 2});
        }
        auto v = grayCode(n - 1);
        int vsize = v.size();
        int mask = 1 << (n-1);
        for (int i=vsize-1; i>=0; i--){
            int val = v[i];
            v.push_back(val | mask);
        }
        return move(v);
    }
};
