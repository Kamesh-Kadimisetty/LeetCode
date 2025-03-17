class Solution {
public:
    vector<pair<int,int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& visited,int &cnt){
        int n=grid.size();
        int m=grid[0].size();
        cnt++;
        visited[row][col]=1;
        for(auto [dr,dc]:directions){
            int nr=row+dr;
            int nc=col+dc;
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !visited[nr][nc]){
                dfs(nr,nc,grid,visited,cnt);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int maxcnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=0;
                if(grid[i][j]==1 && !visited[i][j]){
                    dfs(i,j,grid,visited,cnt);
                    maxcnt=max(maxcnt,cnt);
                }
            }
        }
        return maxcnt;
    }
};