class Solution {
public:
    vector<pair<int,int>>directions={{1,0},{-1,0},{0,-1},{0,1}};
    void dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&visited){
        int n=grid.size();
        int m=grid[0].size();       
        visited[row][col]=1;
        for(auto [dr,dc]:directions){
            int nr=row+dr;
            int nc=col+dc;
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 && !visited[nr][nc]){
                dfs(nr,nc,grid,visited);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        //Marking borders
        for(int i=0;i<n;i++){
            //first column
            if(grid[i][0]==1 && !visited[i][0]){
                dfs(i,0,grid,visited);
            }
            //Last column
            if(grid[i][m-1]==1 && !visited[i][m-1]){
                dfs(i,m-1,grid,visited);
            }
        }
        for(int i=0;i<m;i++){
            //first row
            if(grid[0][i]==1 && !visited[0][i]){
                dfs(0,i,grid,visited);
            }
            //Last row
            if(grid[n-1][i]==1 && !visited[n-1][i]){
                dfs(n-1,i,grid,visited);
            }
        }
        int total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    total++;
                }
            }
        }
        return total;
    }
};