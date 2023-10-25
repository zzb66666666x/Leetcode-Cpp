class Solution {
private:
    unordered_map<int, int> m;

public:
    int climbStairs(int n) {
        if (n == 0){
            return 0;
        }
        if (n == 1){
            return 1;
        }
        if (n == 2){
            return 2;
        }
        if (m.find(n) != m.end()){
            return m[n];
        }
        int ret = climbStairs(n-1) + climbStairs(n-2);
        m[n] = ret;
        return ret;
    }
};
