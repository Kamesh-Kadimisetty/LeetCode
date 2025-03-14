class Disjointset{
public:
    vector<int>parent,size;
    Disjointset(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int findparent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findparent(parent[node]);
    }
    void unionbysize(int u,int v){
        int ulpu=findparent(u);
        int ulpv=findparent(v);
        if(ulpv==ulpu){
            return;
        }
        if(size[ulpu]>size[ulpv]){
            parent[ulpv]=ulpu;
            size[ulpu]+=size[ulpv];
        }
        else{
            parent[ulpu]=ulpv;
            size[ulpv]+=size[ulpu];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        Disjointset ds(n*n);
        vector<pair<int,int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
        //connecting 1's
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(auto [dr,dc]:directions){
                        int nr=i+dr;
                        int nc=j+dc;
                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                            int node=i*n+j;
                            int adjnode=nr*n+nc;
                            if(ds.findparent(node)!=ds.findparent(adjnode)){
                                ds.unionbysize(node,adjnode);
                            }
                        }
                    }
                }
            }
        }
        int maxsize=0;
        //Now find 0 and connect to neighbours to get maxsize;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int cnt=1;
                    set<int>st;
                    for(auto [dr,dc]:directions){
                        int nr=i+dr;
                        int nc=j+dc;
                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                            int adjnode=nr*n+nc;
                            st.insert(ds.findparent(adjnode));
                        }
                    }
                    for(auto it:st){
                        cnt+=ds.size[it];
                    }
                    maxsize=max(maxsize,cnt);
                }
            }
        }
        return maxsize==0?n*n:maxsize;
    }
};