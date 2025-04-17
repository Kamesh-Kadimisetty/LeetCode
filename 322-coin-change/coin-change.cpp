class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        //Base case
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0) dp[0][t]=t/coins[0];
            else dp[0][t]=1e9;
        }
        //DP table
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                int notpick=dp[ind-1][target];
                int pick=1e9;
                if(target>=coins[ind]){
                    pick=1+dp[ind][target-coins[ind]];
                }
                dp[ind][target]=min(pick,notpick);
            }
        }
        int ans=dp[n-1][amount];
        return ans==1e9?-1:ans;
    }
};