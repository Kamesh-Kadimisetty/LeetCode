class Solution {
public:
    int func(int ind,int buy,vector<int>& prices,vector<vector<int>>&dp,int fee){
        int n=prices.size();
        if(ind==n){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy){
            profit=max(-prices[ind]+func(ind+1,0,prices,dp,fee),func(ind+1,1,prices,dp,fee));
        }
        else{
            profit=max(prices[ind]-fee+func(ind+1,1,prices,dp,fee),func(ind+1,0,prices,dp,fee));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return func(0,1,prices,dp,fee);
    }
};