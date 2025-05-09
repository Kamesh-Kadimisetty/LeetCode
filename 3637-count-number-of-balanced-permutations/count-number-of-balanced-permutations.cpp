const long long MOD = 1e9 + 7;
long long factorial[101] {1,1}, invFactorial[101] {1,1};
class Solution {
public:
    int countBalancedPermutations(const string& numStr) {
        int n = numStr.size();
        int freq[10] {};
        int targetSum = 0;
        for(char c : numStr) {
            freq[c-'0']++;
            targetSum += (c-'0');
        }
        if(targetSum % 2 == 1) return 0;
        targetSum /= 2;
        
        int targetLen = n/2;
        long long ways = (factorial[targetLen] * factorial[n-targetLen]) % MOD;

        vector dp(10, vector(targetLen + 1, vector(targetSum + 1, -1)));
        auto go = [&](this auto&& go, int i, int len1, int sum1) -> long long {
            if(i >= 10) {
                if(len1 == targetLen && sum1 == targetSum) return ways;
                return 0LL;
            }
            if(len1 > targetLen || sum1 > targetSum) {
                return 0LL;
            }
            if(dp[i][len1][sum1] >= 0) return dp[i][len1][sum1];
            long long ans = 0;
            for(int take = 0; take <= freq[i]; take++) {
                long long w = go(i + 1, len1 + take, sum1 + take * i);
                w = (w * invFactorial[take]) % MOD;
                w = (w * invFactorial[freq[i]-take]) % MOD;
                ans = (ans + w) % MOD;
            }
            return dp[i][len1][sum1] = ans;
        };
        return go(0, 0, 0);
    }
};
long long mod_exp(long long base, long long exp) {
    base %= MOD;
    long long ans = 1;
    while(exp > 0) {
        if(exp & 1) {
            ans = (ans * base) % MOD;
        }
        exp >>= 1;
        base = (base * base) % MOD;
    }
    return ans;
}
auto init = [](){
    cin.tie(0)->sync_with_stdio(0);
    for(int i = 2; i <= 81; i++) {
        factorial[i] = (i * factorial[i - 1]) % MOD;
        invFactorial[i] = mod_exp(factorial[i], MOD-2);
    }
    return true;
}();