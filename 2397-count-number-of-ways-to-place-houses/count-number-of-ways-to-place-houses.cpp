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
        if(n==1) return 4;
        if(n==2) return 9;
        vector<int>dp(n+1,0);
        dp[1]=2;
        dp[2]=3;
        for(int i=3;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])%MOD;
        }
        long long x=dp[n];
        return (x*x)%MOD;
    }
};