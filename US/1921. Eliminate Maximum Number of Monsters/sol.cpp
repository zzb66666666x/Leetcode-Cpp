class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        priority_queue<int> q;
        for (int i=0; i<n; i++){
            int step = dist[i]/speed[i] + (dist[i]%speed[i] == 0 ? 0 : 1);
            q.push(-1 * step);
        }
        int t=0;
        while (!q.empty()){
            q.pop();
            t++;
            int step = -1 * q.top();
            if (step <= t) 
                return t;
        }
        return n;
    }
};
