class Solution {
public:
    vector<pair<int,int>>directions={{1,0},{-1,0},{0,-1},{0,1}};
    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>&visited){
        int n=board.size();
        int m=board[0].size();       
        visited[row][col]=1;
        for(auto [dr,dc]:directions){
            int nr=row+dr;
            int nc=col+dc;
            if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc]=='O' && !visited[nr][nc]){
                dfs(nr,nc,board,visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !visited[i][0]){
                dfs(i,0,board,visited);
            }
            if(board[i][m-1]=='O' && !visited[i][m-1]){
                dfs(i,m-1,board,visited);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && !visited[0][i]){
                dfs(0,i,board,visited);
            }
            if(board[n-1][i]=='O' && !visited[n-1][i]){
                dfs(n-1,i,board,visited);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};