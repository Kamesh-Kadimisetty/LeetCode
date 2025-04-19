class Solution {
public:
    int func(int ind,int target,vector<int>& coins,vector<vector<int>> &dp){
        if(ind==0){
            if(target==0 || target%coins[ind]==0) return 1;
            else return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int pick=0;
        int notpick=func(ind-1,target,coins,dp);
        if(target>=coins[ind]){
            pick=func(ind,target-coins[ind],coins,dp);
        }
        return dp[ind][target]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return func(n-1,amount,coins,dp);
    }
};