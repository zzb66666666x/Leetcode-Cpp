class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int first, last;
        int n = seats.size();
        for (int i=0; i<n; i++){
            if (seats[i]){
                first = i;
                break;
            }
        }
        for (int i=n-1; i>=0; i--){
            if (seats[i]){
                last = i;
                break;
            }
        }
        int max_range = 0;
        int len = 0;
        for (int i=first+1; i<=last; i++){
            if (seats[i]){
                if (len==0){
                    continue;
                }else{
                    max_range = max(max_range, len);
                    len = 0;
                }
            }else{
                len++;
            }
        }
        return max((max_range-1)/2+1, max(first, n-last-1));
    }
};
