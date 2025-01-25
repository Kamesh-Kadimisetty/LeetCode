class Solution {
public:
    // int func(int ind,vector<int>&nums,vector<int>&dp){
    //     if(ind==0) return nums[ind];
    //     if(ind<0) return 0;

    //     if(dp[ind]!=-1)return dp[ind];
    //     int pick=nums[ind]+func(ind-2,nums,dp);//picking
    //     int notpick=0+func(ind-1,nums,dp);//not picking
    //     return dp[ind]=max(pick,notpick);
    // }
    int rob(vector<int>& nums){
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i];
            int notpick=0+dp[i-1];
            if(i>1){
                pick+=dp[i-2];
            }
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
};