class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<pair<int,int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>>mineffort(n,vector<int>(m,INT_MAX));
        mineffort[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,
                        vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==m-1) return diff;
            for(auto [dr,dc]:directions){
                int nr=row+dr;
                int nc=col+dc;
                if(nr>=0 && nr<n && nc>=0 && nc<m ){
                    int neweffort=max(abs(heights[nr][nc]-heights[row][col]),diff);
                    if(neweffort<mineffort[nr][nc]){
                        mineffort[nr][nc]=neweffort;
                        pq.push({neweffort,{nr,nc}});
                    }
                }
            }
        }
        return mineffort[n-1][m-1];
    }
};