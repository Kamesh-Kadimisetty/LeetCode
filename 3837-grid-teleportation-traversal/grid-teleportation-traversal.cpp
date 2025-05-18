class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        vector<vector<pair<int,int>>> portols(26);
        vector<bool>visited(26,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch=matrix[i][j];
                if(ch>='A' && ch<='Z'){
                    portols[ch-'A'].push_back({i,j});
                }
            }
        }

        vector<pair<int,int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq; //{dist,i,j}
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int d=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(dist[x][y]<d)  continue;
            if(x==n-1 && y==m-1) return d;
            char ch=matrix[x][y];

            if(ch>='A' && ch<='Z'){
                int id=ch-'A';
                if(!visited[id]){
                    visited[id]=true;
                    for(auto& [a,b]:portols[id]){
                        if(a==x && b==y) continue;
                        if(dist[a][b]>d){
                            dist[a][b]=d;
                            pq.push({d,{a,b}});
                        }
                    }
                }
            }

            for(auto [dr,dc]:directions){
                int nr=x+dr;
                int nc=y+dc;
                if(nr>=0 && nr<n && nc>=0 && nc<m && matrix[nr][nc]!='#'){
                    if(dist[nr][nc]>d+1){
                        dist[nr][nc]=d+1;
                        pq.push({d+1,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};