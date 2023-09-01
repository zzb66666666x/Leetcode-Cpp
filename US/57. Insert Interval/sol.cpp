class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0){
            intervals.push_back(newInterval);
            return move(intervals);
        }
        vector<vector<int>> ret;
        int flag = 0;
        for (auto& v: intervals){
            if (flag == -1){
                ret.push_back(v);
                continue;
            }
            if (v[1] < newInterval[0] || v[0] > newInterval[1]){
                ret.push_back(v);
                if (flag > 0){
                    ret.push_back(newInterval);
                    flag = -1;
                }
            }else{
                // vector<int> merged = {min(v[0], newInterval[0]), max(v[1], newInterval[1])};
                newInterval[0] = min(v[0], newInterval[0]);
                newInterval[1] = max(v[1], newInterval[1]);
                flag = 1;
            }
        }
        if(flag >= 0){
            ret.push_back(newInterval);
        }
        sort(ret.begin(), ret.end(), [](auto& a, auto& b){return a[0]<b[0];});
        return ret;
    }
};
