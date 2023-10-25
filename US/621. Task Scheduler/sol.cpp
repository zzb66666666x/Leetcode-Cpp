class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counter(26, 0);
        vector<int> cool(26, 0);
        for (auto c : tasks){
            counter[c-'A']++;
        }
        int time = 0;
        while (1){
            int all_done = 1;
            int found = -1;
            int max_left = 0;
            for (int i=0; i<26; i++){
                if (counter[i] > 0){
                    all_done = 0;
                    if (cool[i] == 0 && counter[i] > max_left){
                        found = i;
                        max_left = counter[i];
                    }else if (cool[i] > 0){
                        cool[i]--;
                    }
                }
            }
            if (all_done){
                break;
            }
            if (found >= 0){
                counter[found]--;
                cool[found] = n;
            }
            time++;
        }
        return time;
    }
};
