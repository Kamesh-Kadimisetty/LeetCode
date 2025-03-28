class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n=grid.size();
        int m=grid[0].size();
        int k=queries.size();
        vector<int>result(k,0);
        vector<pair<int,int>>sortedqueries;
        for(int i=0;i<k;i++){
            sortedqueries.push_back({queries[i],i});
        }
        sort(sortedqueries.begin(),sortedqueries.end());
        vector<vector<int>>visited(n,vector<int>(m,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
                    greater<pair<int,pair<int,int>>>>pq;  //{val,{row,col}}
        pq.push({grid[0][0],{0,0}});
        visited[0][0]=1;
        int total=0;
        vector<pair<int,int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
        for(auto it:sortedqueries){
            int query=it.first;
            int index=it.second;
            while(!pq.empty() && pq.top().first<query){
                int val=pq.top().first;
                int row=pq.top().second.first;
                int col=pq.top().second.second;
                pq.pop();
                total++;
                for(auto [dr,dc]:directions){
                    int nr=row+dr;
                    int nc=col+dc;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc]){
                        pq.push({grid[nr][nc],{nr,nc}});
                        visited[nr][nc]=1;
                    }
                }
            }
            result[index]=total;
        }
        return result;
    }
};