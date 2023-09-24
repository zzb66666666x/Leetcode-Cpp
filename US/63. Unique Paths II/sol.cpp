class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dirs = {{1, 0}, {0, 1}};
        vector<vector<int>> mem(m, vector<int>(n, 0));
        int count = 0;
        function<void(int, int)> dfs = [&](int i, int j) -> void{
            if (obstacleGrid[i][j])
                return;
            if (i == m-1 && j == n-1){
                count ++;
                return;
            }
            if (mem[i][j] > 0){
                count += mem[i][j];
                return;
            }
            int oldCnt = count;
            for (auto& d: dirs){
                int nexti = i + d[0];
                int nextj = j + d[1];
                if (nexti >= 0 && nexti < m && nextj >= 0 && nextj < n){
                    dfs(nexti, nextj);
                }
            }
            int delta = count - oldCnt;
            mem[i][j] = delta;
        };
        dfs(0, 0);
        return count;
    }
};
