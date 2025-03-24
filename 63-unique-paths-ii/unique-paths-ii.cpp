class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1)return 0;
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1)dp[i][j]=0;
                else if(i==0 && j==0)continue;
                else{
                    int left=0,down=0;
                    if(i>0)left=dp[i-1][j];
                    if(j>0)down=dp[i][j-1];
                    dp[i][j]=left+down;
                }
            }
        }
        return dp[n-1][m-1];
    }
};