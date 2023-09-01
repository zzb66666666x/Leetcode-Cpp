class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> m;
        m.emplace(arr[0], 1);
        int res = 1;
        int mod = 1000000000+7;
        for (int i=1; i<arr.size(); i++){
            int c = arr[i];
            m[c] = 1; // add self tree
            res = (res+1)%mod;
            for (int j=0; j<i; j++){
                int b = arr[j];
                if (c % b == 0){
                    int a = c / b;
                    if (m.find(a) != m.end()){
                        long long newtrees = ((long long)m[a] * (long long)m[b])%mod;
                        m[c] = (m[c] + newtrees)%mod;
                        res = (res+newtrees)%mod;
                    }
                }
            }
        }
        //debug: print table
        // for (auto [k, v] : m){
        //     cout<<k<<" "<<v<<endl;
        // }
        return res;
    }
};
