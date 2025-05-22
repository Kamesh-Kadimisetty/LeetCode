class Solution {
public:
    vector<pair<int,int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(int i,int j,vector<vector<int>>& matrix,vector<vector<int>> &memo){
        if(memo[i][j]!=0) return memo[i][j];
        int n=matrix.size(),m=matrix[0].size();    
        int maxpath=1;
        for(auto it:directions){
            int nr=i+it.first,nc=j+it.second;
            if(nr>=0 && nr<n && nc>=0 && nc<m && matrix[i][j]<matrix[nr][nc]){
                maxpath=max(maxpath,1+dfs(nr,nc,matrix,memo));
            }
        }
        return memo[i][j]=maxpath;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>memo(n,vector<int>(m,0));
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result=max(result,dfs(i,j,matrix,memo));
            }
        }
        return result;
    }
};