class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> vertical(n, 0);
        vector<int> horiz(m, 0);
        for (int i=0; i<m; i++){
            int s = 0;
            for (int j=0; j<n; j++){
                s += grid[i][j];
            }
            horiz[i] = s;
        }
        for (int j=0; j<n; j++){
            int s = 0;
            for (int i=0; i<m; i++){
                s += grid[i][j];
            }
            vertical[j] = s;
        }
        int total = 0;
        for (auto e: vertical){
            total += e;
        }
        int single = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] == 1 && vertical[j] ==1 && horiz[i] == 1){
                    single ++;
                }
            }
        }
        return total - single;
    }
};
