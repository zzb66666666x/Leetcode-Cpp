class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
	int n = nums.size();
	vector<int> fl(n, 1);
	vector<int> fr(n, 1);
	for(int i=0; i<n; i++){
	    for (int j=0; j<i; j++){
		if (nums[i] > nums[j]){
		    fl[i] = max(fl[i], fl[j]+1);
		}
	    }
	}
	for (int i=n-1; i>=0; i--){
	    for (int j=n-1; j>i; j--){
		if (nums[i] > nums[j]){
		    fr[i] = max(fr[i], fr[j]+1);
		}
	    }
	}
	int ret = 0;
	for (int i=1; i<n-1; i++){
	    // cout<<"i="<<i<<" "<<fl[i] << " " <<fr[i]<<endl;
	    if(fl[i]>1 && fr[i]>1)
		ret = max(ret, fl[i]+fr[i]-1);
	}
	return n-ret;
    }
};
