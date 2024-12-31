class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&visited){
        visited[node]=1;
        int n=adj.size();
        for(int i=0;i<n;i++){
            if(!visited[i] && adj[node][i]==1){
                dfs(i,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt=0;
        int n=isConnected.size();
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,isConnected,visited);
            }
        }
        return cnt;
    }
};