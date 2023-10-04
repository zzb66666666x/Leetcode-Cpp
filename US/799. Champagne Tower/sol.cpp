class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row = {(double)poured};
        for (int i = 1; i <= query_row; i++) {
            vector<double> nextRow(i + 1, 0.0);
            for (int j = 0; j < row.size(); j++) {
                double volume = row[j];
                if (volume > 1) {
                    nextRow[j] += (volume - 1) / 2;
                    nextRow[j + 1] += (volume - 1) / 2;
                }
            }
            row = nextRow;
        }            
        return min(1.0, row[query_glass]);
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/champagne-tower/solutions/1979893/xiang-bin-ta-by-leetcode-solution-y87c/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

