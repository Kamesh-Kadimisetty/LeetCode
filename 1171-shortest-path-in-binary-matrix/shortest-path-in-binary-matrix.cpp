class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
        int n=grid.size();
        if(grid[0][0]!=0){
            return -1;
        }
        if(n==1)return 1;
        queue<pair<int,pair<int,int>>>pq;
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        distance[0][0]=1;
        pq.push({1,{0,0}});
        while(!pq.empty()){
            auto cell=pq.front();
            pq.pop();
            int wt=cell.first;
            int row=cell.second.first;
            int col=cell.second.second;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    // if(i==0 && j==0){
                    //     continue;
                    // }
                    int nr=row+i;
                    int nc=col+j;
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && distance[nr][nc]>wt+1){
                        distance[nr][nc]=wt+1;
                        if(nr==n-1 && nc==n-1) return wt+1;
                        pq.push({wt+1,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};