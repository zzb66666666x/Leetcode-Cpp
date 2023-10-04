// PERSONAL SOLUTION: 
// class Solution {
// public:
//     bool checkPred(string s1, string s2){
//         if (s1.size() + 1 != s2.size())
//             return false;
//         int i = 0, j=0;
//         int credit = 1;
//         while (i < s1.size() && j < s2.size()){
//             if (s1[i] == s2[j]){
//                 i++;
//                 j++;
//             }else{
//                 if (credit>0){
//                     j++;
//                     credit--;
//                 }else{
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }

//     int longestStrChain(vector<string>& words) {
//         sort(words.begin(), words.end(), [](auto& a, auto& b){
//             return a.size() < b.size();
//         });
//         int n = words.size();
//         vector<int> dp(n, 1);
//         int maxval = 1;
//         for (int i=1; i<n; i++){
//             for (int j=0; j<i; j++){
//                 if (checkPred(words[j], words[i])){
//                     dp[i] = max(dp[i], dp[j]+1);
//                     maxval = max(maxval, dp[i]);
//                 }
//             }
//         }
//         return maxval;
//     }
// };

// OFFICIAL SOLUTION
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> cnt;
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        int res = 0;
        for (string word : words) {
            cnt[word] = 1;
            for (int i = 0; i < word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (cnt.count(prev)) {
                    cnt[word] = max(cnt[word], cnt[prev] + 1);
                }
            }
            res = max(res, cnt[word]);
        }
        return res;
    }
};
