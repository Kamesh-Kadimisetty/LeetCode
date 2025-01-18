class Solution {
public:
    bool isvalid(int r,int c,int n,int m){
        return r>=0 && r<n && c>=0 && c<m;
    }
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>mincost(n,vector<int>(m,INT_MAX));
        deque<pair<int,int>>dq;
        dq.push_back({0,0});
        mincost[0][0]=0;
        vector<pair<int,int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
        while(!dq.empty()){
            auto [row,col]=dq.front();
            dq.pop_front();
            for(int i=0;i<4;i++){
                int r=row+directions[i].first;
                int c=col+directions[i].second;
                int cost=grid[row][col]!=i+1?1:0;

                if(isvalid(r,c,n,m) && mincost[row][col]+cost<mincost[r][c]){
                    mincost[r][c]=mincost[row][col]+cost;
                    if(cost==0){
                        dq.push_front({r,c});
                    }
                    else{
                        dq.push_back({r,c});
                    }
                }
            }
        }
        return mincost[n-1][m-1];
    }
};