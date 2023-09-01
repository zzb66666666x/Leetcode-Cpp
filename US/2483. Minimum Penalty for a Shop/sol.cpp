class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        // vector<pair<int, int>> dp(n, {100000, 100000});
        int Ycnt = 0;
        int Ncnt = 0;
        for (auto c : customers){
            if (c == 'Y'){
                Ycnt ++;
            }else{
                Ncnt ++;
            }
        }
        // cout<<"init penalty="<<Ycnt<<endl;
        pair<int, int> best = {Ycnt, 0};
        pair<int, int> penalty = {Ycnt, 0};
        for (int i=0; i<customers.size(); i++){
            // close after ith hour
            char c = customers[i];
            int delta = 0;
            if (c == 'Y'){
                // cout<<"Y"<<endl;
                delta = -1;
            }else{
                // cout<<"N"<<endl;
                delta = 1;
            }
            penalty.first += delta;
            penalty.second ++;
            if (penalty.first < best.first){
                best.first = penalty.first;
                best.second = penalty.second;
            }
            // cout<<"penalty="<<penalty.first<<endl;
        }
        return best.second;
    }
};

