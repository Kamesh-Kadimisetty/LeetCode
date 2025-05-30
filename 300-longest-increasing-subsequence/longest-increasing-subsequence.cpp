class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        for(int ind=0;ind<n;ind++){
            int x=dp[ind];
            for(int prev=0;prev<=ind-1;prev++){
                if(nums[ind]>nums[prev]){
                    dp[ind]=max(dp[ind],x+dp[prev]);
                }
            }
        }
        int maxlen=0;
        for(auto it:dp) maxlen=max(maxlen,it);
        return maxlen;
    }
};