class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> arr(n, 0);
        int c = 1;
        for (int i=0; i<=n-1; i++){
            if (i == n-1){
                arr[i] = max(arr[i], c);
                break;
            }
            int nexti = i+1;
            if (ratings[nexti] > ratings[i]){
                arr[i] = max(arr[i], c);
                c++;
            }else{
                arr[i] = max(arr[i], c);
                c=1;
            }
        }
        c = 1;
        int ret = 0;
        for (int i=n-1; i>=0; i--){
            if (i == 0){
                arr[i] = max(arr[i], c);
                ret += arr[i];
                break;
            }
            int nexti = i-1;
            if (ratings[nexti] > ratings[i]){
                arr[i] = max(arr[i], c);
                c++;
            }else{
                arr[i] = max(arr[i], c);
                c=1;
            }
            ret += arr[i];
        }
        return ret;
    }
};
