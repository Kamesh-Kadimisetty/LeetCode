class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>res(n,vector<int>(m,-1));
        vector<pair<int,int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                    res[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            for (const auto& direction : directions) {
                int dr = direction.first;
                int dc = direction.second;
                int nr=row+dr;
                int nc=col+dc;
                if(nr>=0 && nr<n && nc>=0 && nc<m && res[nr][nc]==-1){
                    q.push({{nr,nc},dist+1});
                    res[nr][nc] = dist + 1;
                }
                
            }
        }
        return res;
    }
};