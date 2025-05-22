class Solution {
public:
    int func(int ind,int buy,vector<int>& prices,vector<vector<vector<int>>>&dp,int chns){
        int n=prices.size();
        if(ind==n || chns==0){
            return 0;
        }
        if(dp[ind][buy][chns]!=-1) return dp[ind][buy][chns];
        int profit=0;
        if(buy){
            profit=max(-prices[ind]+func(ind+1,0,prices,dp,chns),func(ind+1,1,prices,dp,chns));
        }
        else{
            profit=max(prices[ind]+func(ind+1,1,prices,dp,chns-1),func(ind+1,0,prices,dp,chns));
        }
        return dp[ind][buy][chns]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return func(0,1,prices,dp,2);
    }
};