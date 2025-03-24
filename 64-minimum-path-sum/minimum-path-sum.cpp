class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        dp[0][0]=grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) continue;
                int down=1e9,right=1e9;
                if(i>0) down=grid[i][j]+dp[i-1][j];
                if(j>0) right=grid[i][j]+dp[i][j-1];
                dp[i][j]=min(down,right);
            }
        }
        return dp[n-1][m-1];
    }
};