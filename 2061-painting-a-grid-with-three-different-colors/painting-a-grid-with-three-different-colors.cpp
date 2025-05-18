class Solution {
public:
    int dp[1001][1024]={};
    int colorTheGrid(int m, int n, int i=0, int j=0, int cur=0 ,int prev=0) {
        if(i==m){
            return colorTheGrid(m,n,0,j+1,0,cur);
        }
        if (j == n){
            return 1;
        }
        if (i == 0 && dp[j][prev]){
            return dp[j][prev];
        }
        int res = 0, up = i == 0 ? 0 : (cur >>  ((i - 1) * 2)) & 3, left = prev >> (i * 2) & 3;
        for (int k = 1; k <= 3; ++k){
            if (k != left && k != up)
                res = (res + colorTheGrid(m, n, i + 1, j, cur + (k << (i * 2)), prev)) % 1000000007;
        }
        if (i == 0) dp[j][prev] = res;
        return res;
        }
};