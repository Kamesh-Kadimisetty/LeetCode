class Solution {
public:
    void dfs(int node,int d,vector<int>&visited,vector<int>&depth,vector<vector<int>>&adj){
        visited[node]=1;
        depth[node]=d;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,d+1,visited,depth,adj);
            }
        }
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        int MOD=1e9+7;
        vector<vector<int>>adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>visited(n+1,0);
        vector<int>depth(n+1,0);
        dfs(1,0,visited,depth,adj);
        int maxdepth=0;
        for(auto it:depth){
            maxdepth=max(maxdepth,it);
        }
        cout<<maxdepth;
        if(maxdepth==1) return 1;
        int result=2;
        for(int i=0;i<maxdepth-2;i++){
            result=(result*2)%MOD;
        }
        // return pow(2,maxdepth-1);
        return result;
    }
};