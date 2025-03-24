class Solution {
public:
    int func(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        int n=grid.size();
        int m=grid[0].size();
        if(i>n-1 || j>m-1)return 1e9;
        if(i==n-1 && j==m-1)return grid[i][j];
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=0,down=0;
        right=grid[i][j]+func(i+1,j,grid,dp);
        down=grid[i][j]+func(i,j+1,grid,dp);
        return dp[i][j]=min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(0,0,grid,dp);
    }
};