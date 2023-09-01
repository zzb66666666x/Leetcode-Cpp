class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret;
        for (int i=0; i<=n; i++){
            int mask = 1 << 18;
            int cnt = 0;
            while (mask > 0){
                if (mask & i){
                    cnt ++;
                }
                mask >>= 1;
            }
            ret.push_back(cnt);
        }
        return move(ret);
    }
};

