class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        for (int i=n-2; i>=0; i--){
            int curtemp = temperatures[i];
            int j = i + 1;
            while (j < n){
                if (temperatures[j] <= curtemp){
                    if (answer[j] == 0){
                        answer[i] = 0;
                        break;
                    }
                    j += answer[j];
                }else{
                    answer[i] = j - i;
                    break;
                }
            }
        }
        return answer;
    }
};
