// https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/

class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, vector<int>> m;
        for (int i=0; i<s.length(); i++){
            char c = s[i];
            auto it = m.find(c);
            if (it != m.end()){
                auto& vec = m[c];
                vec.push_back(i);
            }else{
                vector<int> vec(1, -1);
                vec.push_back(i);
                m[c] = move(vec);
            }
        }
        auto it = m.begin();
        int ret = 0;
        while (it != m.end()){
            auto& vec = it->second;
            vec.push_back(s.length());
            for (int i=1; i<vec.size()-1; i++){
                ret += (vec[i]-vec[i-1]) * (vec[i+1] - vec[i]);
            }
            it++;
        }
        return ret;
    }
};
