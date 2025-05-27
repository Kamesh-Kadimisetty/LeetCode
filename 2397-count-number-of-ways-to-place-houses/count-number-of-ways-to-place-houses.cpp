class Solution {
public:
    int MOD=1e9+7;
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