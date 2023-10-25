class Solution {
public:
    int paintWalls(vector<int> &cost, vector<int> &time) {
        int n = cost.size(), f[n + 1];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            int c = cost[i], t = time[i] + 1; // 注意这里加一了
            for (int j = n; j; j--)
                f[j] = min(f[j], f[max(j - t, 0)] + c);
        }
        return f[n];
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/painting-the-walls/solutions/2312808/xuan-huo-bu-xuan-de-dian-xing-si-lu-by-e-ulcd/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
