class Solution {
public:
    int sum=0;
    vector<pair<int,int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int r,int c){
        int n=grid.size();
        int m=grid[0].size();
        sum+=grid[r][c];
        visited[r][c]=1;
        for(auto [dr,dc]:directions){
            int nr=r+dr;
            int nc=c+dc;
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]>0 && !visited[nr][nc]){
                dfs(grid,visited,nr,nc);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0 && !visited[i][j]){
                    dfs(grid,visited,i,j);
                    ans=max(ans,sum);
                    sum=0;
                }
            }
        }
        return ans;
    }
};