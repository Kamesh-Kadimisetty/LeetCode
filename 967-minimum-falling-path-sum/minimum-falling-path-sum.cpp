class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix){
        int n=matrix.size(),ans=1e9;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int d1=1e9,d2=1e9,d=1e9;
                if(j>0)d1=matrix[i][j]+dp[i-1][j-1];
                        d=matrix[i][j]+dp[i-1][j];
                if(j<n-1)d2=matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=min({d,d1,d2});
            }
        }
        for(int j=0;j<n;j++){
            ans=min(ans,dp[n-1][j]);
        }
        return ans;
    }
};