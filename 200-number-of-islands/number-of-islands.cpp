class Solution {
public:
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>&visited){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        visited[row][col]=1;
        q.push({row,col});
        vector<pair<int,int>>directons={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for (auto [dr,dc]:directons) {
                int delr = r + dr;      
                int delc = c + dc;
                if (delr >= 0 && delr < n && delc >= 0 && delc < m &&
                    grid[delr][delc] == '1' && !visited[delr][delc]) {
                    visited[delr][delc] = 1; 
                    q.push({delr, delc});    
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0; 
        int n=grid.size();
        int m=grid[0].size();
        int total=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    total++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return total;
    }
};