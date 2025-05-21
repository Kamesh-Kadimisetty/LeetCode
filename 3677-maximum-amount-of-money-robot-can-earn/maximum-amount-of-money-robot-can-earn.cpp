class Solution {
public:
    int func(int i,int j,vector<vector<int>>& coins,int chances,vector<vector<vector<int>>> &dp){
        int n=coins.size(),m=coins[0].size();
        if(i==n-1 && j==m-1){
            if(coins[i][j]<0 && chances>0) return 0;
            return coins[i][j];
        } 
        if(i>=n || j>=m) return -1e9;
        if(dp[i][j][chances]!=INT_MIN) return dp[i][j][chances];
        
        int take=INT_MIN,nottake=INT_MIN;
        take=max(coins[i][j]+func(i+1,j,coins,chances,dp),
                coins[i][j]+func(i,j+1,coins,chances,dp));

        if(chances>0 && coins[i][j]<0){
            nottake=max(func(i+1,j,coins,chances-1,dp),
                        func(i,j+1,coins,chances-1,dp));
        }
        return dp[i][j][chances]=max(take,nottake);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size(),m=coins[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));
        return func(0,0,coins,2,dp);
    }
};