class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int chns=1;chns<3;chns++){
                    int profit=0;
                    if(buy){
                        profit=max(-prices[ind]+dp[ind+1][0][chns],dp[ind+1][1][chns]);
                    }
                    else{
                        profit=max(prices[ind]+dp[ind+1][1][chns-1],dp[ind+1][0][chns]);
                    }
                    dp[ind][buy][chns]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
};