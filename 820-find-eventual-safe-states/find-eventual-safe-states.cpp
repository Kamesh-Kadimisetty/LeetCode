class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&visited,vector<int>&pathvisited,vector<int>&safenodes){
        visited[node]=1;
        pathvisited[node]=1;
        safenodes[node]=0;
        for(auto it:adj[node]){
            if(!visited[it]){
                if(dfs(it,adj,visited,pathvisited,safenodes)==true){
                    safenodes[node]=0;
                    return true;
                }
            }
            else if(visited[it] && pathvisited[it]){
                safenodes[node]=0;
                return true;
            }
        }
        safenodes[node]=1;
        pathvisited[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>visited(V,0);
        vector<int>pathvisited(V,0);
        vector<int>safenodes(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,graph,visited,pathvisited,safenodes);
            }
        }
        vector<int>result;
        for(int i=0;i<V;i++){
            if(safenodes[i]==1){
                result.push_back(i);
            }
        }
        return result;
    }
};