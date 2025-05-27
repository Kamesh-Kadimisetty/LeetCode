class Solution {
public:
    int MOD=1e9+7;
    int func(int ind,int canplace,int plots,vector<vector<int>>&dp){
        if(ind==plots) return 1;
        if(dp[ind][canplace]!=-1) return dp[ind][canplace];
        int put=0,notput=0;
        if(canplace==1){
            put=func(ind+1,0,plots,dp);
            notput=func(ind+1,1,plots,dp);
        }
        else{
            notput=func(ind+1,1,plots,dp);
        }
        return dp[ind][canplace]=(put+notput)%MOD;
    }
    int countHousePlacements(int n) {
        vector<vector<int>>dp(n,vector<int>(2,-1));
        long long x= func(0,1,n,dp);
        return (x*x)%MOD;
    }
};