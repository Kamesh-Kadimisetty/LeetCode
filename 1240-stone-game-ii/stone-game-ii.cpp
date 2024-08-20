class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();

        vector<vector<int>> dp (n,vector<int>(n+1,0));
        vector<int> suffixsum(n,0);
        suffixsum[n - 1] = piles[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixsum[i] = suffixsum[i + 1] + piles[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int m = 1; m <= n; m++) {
                if (i + 2 * m >= n) {
                    dp[i][m] = suffixsum[i];
                } else {
                    for (int x = 1; x <= 2 * m; x++) {
                        dp[i][m] = max(dp[i][m], suffixsum[i] - dp[i + x][max(m, x)]);
                    }
                }
            }
        }
        
        return dp[0][1];
    }
};
