class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result=0,imax=0,dmax=0;
        for(int k=0;k<nums.size();k++){
            result=max(result,(long long)dmax*nums[k]);
            dmax=max(dmax,imax-nums[k]);
            imax=max(imax,(long long)nums[k]);
        }
        return result;
    }
};