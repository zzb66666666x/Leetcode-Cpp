class Solution {
private:
    int f[51][51][101];
    static constexpr int mod = 1000000007;

public:
    int numOfArrays(int n, int m, int k) {
        // 不存在搜索代价为 0 的数组
        if (!k) {
            return 0;
        }
        
        memset(f, 0, sizeof(f));
        // 边界条件，所有长度为 1 的数组的搜索代价都为 1
        for (int j = 1; j <= m; ++j) {
            f[1][1][j] = 1;
        }
        for (int i = 2; i <= n; ++i) {
            // 搜索代价不会超过数组长度
            for (int s = 1; s <= k && s <= i; ++s) {
                for (int j = 1; j <= m; ++j) {
                    f[i][s][j] = (long long)f[i - 1][s][j] * j % mod;
                    for (int j0 = 1; j0 < j; ++j0) {
                        f[i][s][j] += f[i - 1][s - 1][j0];
                        f[i][s][j] %= mod;
                    }
                }
            }
        }

        // 最终的答案是所有 f[n][k][..] 的和
        // 即数组长度为 n，搜索代价为 k，最大值任意
        int ans = 0;
        for (int j = 1; j <= m; ++j) {
            ans += f[n][k][j];
            ans %= mod;
        }
        return ans;
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/solutions/514326/sheng-cheng-shu-zu-by-leetcode-solution-yswf/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
