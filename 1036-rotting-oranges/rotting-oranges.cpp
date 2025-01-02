class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        // {{},}
        vector<pair<int,int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
        int fresh=0,totaltime=0,rotten=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int time=q.front().second;
            q.pop();
            totaltime=max(totaltime,time);
            for(auto [dr,dc]:directions){
                int nr=r+dr;
                int nc=c+dc;
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    q.push({{nr,nc},time+1});
                    rotten++;
                }
            }
        }
        return fresh==rotten?totaltime:-1;
    }
};