class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>&visited){
        visited[node]=1;
        for(int i =0; i < adj.size(); i++){
            if(adj[node][i]==1&&!visited[i]){
                dfs(i,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n=isConnected.size();
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,isConnected,visited);
            }
        }
        return count;
    }
};