class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> dirs = {
            {0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1} 
        };
        unordered_set<int> qset;
        for (auto& q: queens){
            int key = q[0] * 8 + q[1];
            qset.insert(key);
        }
        vector<vector<int>> ret;  
        for (auto& dir : dirs){
            int i = king[0] + dir[0];
            int j = king[1] + dir[1];
            while (i>=0 && i<8 && j>=0 && j<8){
                int nexti = i + dir[0];
                int nextj = j + dir[1];
                int key = i * 8 + j;
                if (qset.find(key) != qset.end()){
                    ret.emplace_back(vector<int>{i, j});
                    break;
                }
                i = nexti;
                j = nextj;
            }
        }
        return ret;
    }
};
