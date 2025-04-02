class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result=0,dmax=0,imax=0;
        int n=nums.size();
        for(int k=0;k<n;k++){
            result=max(result,(long long)(dmax)*nums[k]);    
            dmax=max(dmax,imax-nums[k]);
            imax=max(imax,(long long)nums[k]);    
        }
        return result;
    }
};