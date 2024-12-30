class Solution {
public:
    int mod=1e9+7;
    int score(int target, vector<int>& dp, int one, int zero){
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;
        if (dp[target] != -1)
            return dp[target];
        long long sum;
        sum =  score(target - one, dp, one, zero) + score(target - zero, dp,one, zero);
        return dp[target] = (sum % (mod));
    }
    int countGoodStrings(int low, int high, int zero, int one){
        vector<int> dp(high + 1, -1);
        int ans = 0;
        for (int i = low; i <= high; i++){
            ans = ((ans % mod) + ( score(i, dp, one, zero) % mod )) % mod;
        }
        return ans;
    }
};