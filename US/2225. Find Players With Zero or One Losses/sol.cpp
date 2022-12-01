// https://leetcode.com/problems/find-players-with-zero-or-one-losses/
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ret;
        unordered_map<int, int>m;
        for (auto& match : matches){
            if (m.count(match[0])==0){
                m[match[0]] = 0;
            }
            if (m.count(match[1])==0){
                m[match[1]] = 1;
            }else{
                m[match[1]] += 1;
            }
        }
        vector<int> ans0, ans1;
        for (auto& p : m){
            if (p.second==0){
                ans0.push_back(p.first);
            }else if (p.second==1){
                ans1.push_back(p.first);
            }
        }
        sort(ans0.begin(), ans0.end());
        sort(ans1.begin(), ans1.end());
        ret.push_back(ans0);
        ret.push_back(ans1);
        return ret;
    }
};
