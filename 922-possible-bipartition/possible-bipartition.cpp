class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>&color,int col){
        color[node]=col;
        for(auto it:adj[node]){
            if(color[it]==-1){
                int x=col==1?0:1;
                if(dfs(it,adj,color,x)==false)return false;
            }
            if(color[it]==col) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto it:dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(dfs(i,adj,color,0)==false) return false;
            }
        }
        return true;
    }
};