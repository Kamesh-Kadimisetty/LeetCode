class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        long long result=0;
        int n=nums.size(),prefix=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            prefix+=nums[i]%mod==k;
            result+=mpp[(prefix-k+mod)%mod];
            mpp[prefix%mod]++;
        }
        return result;
    }
};