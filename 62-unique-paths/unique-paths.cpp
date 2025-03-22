class Solution {
public:
    int func(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i>m-1 || j>n-1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=0,down=0;
        if(i<m-1){
            right=func(i+1,j,m,n,dp);
        }
        if(j<n-1){
            down=func(i,j+1,m,n,dp);
        }
        return dp[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(0,0,m,n,dp);
    }
};