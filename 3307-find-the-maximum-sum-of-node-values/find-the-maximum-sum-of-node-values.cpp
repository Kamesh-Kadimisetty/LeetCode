class Solution {
public:
    long long func(int ind,int iseven,vector<int>&nums,int k,vector<vector<long long>>&dp){
        int n=nums.size();
        if(ind==n){
            return iseven==1?0:INT_MIN;
        }
        if(dp[ind][iseven]!=-1) return dp[ind][iseven];
        long long notpick=nums[ind]+func(ind+1,iseven,nums,k,dp);
        long long pick=(nums[ind]^k)+func(ind+1,iseven^1,nums,k,dp);
        return dp[ind][iseven]=max(pick,notpick);
    }
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        return func(0,1,nums,k,dp);
    }
};