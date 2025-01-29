class Solution {
public:
    bool dfs(int src,int parent,vector<vector<int>>&adj,vector<int>&visited){
        visited[src]=true;
        for(auto it:adj[src]){
            if(!visited[it]){
                if(dfs(it,src,adj,visited)){
                    return true;
                }
            }
            else if(it!=parent){
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n+1);
        for(int i=0;i<n;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            vector<int>visited(n+1,0);
            if(dfs(edges[i][0],-1,adj,visited)){
                return edges[i];
            }
        }
        return {};
    }
};