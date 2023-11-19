class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int val = 0;
        vector<int> stk;
        char sign = '+';
        for (int i=0; i<n; i++){
            char c = s[i];
            int d = c - '0';
            bool isDigit = (d >=0 && d<=9);
            if (isDigit){
                val = val * 10 + d;
            }
            if ((!isDigit && c != ' ') || i == n-1){
                if (sign == '+'){
                    stk.push_back(val);
                }else if (sign == '-'){
                    stk.push_back(-val);
                }else if (sign == '*'){
                    stk[stk.size()-1] *= val;
                }else if (sign == '/'){
                    stk[stk.size()-1] /= val;
                }
                sign = c;
                val = 0;
            }
        }
        int ret = 0;
        for (auto v: stk){
            ret += v;
        }
        return ret;
    }
};
