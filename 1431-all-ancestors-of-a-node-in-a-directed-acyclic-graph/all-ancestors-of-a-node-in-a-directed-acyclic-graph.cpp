class Solution {
public:
    void dfs(int curr,vector<int>&visited,vector<vector<int>>&adj){
        visited[curr]=1;
        for(auto it:adj[curr]){
            if(!visited[it]){
                dfs(it,visited,adj);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>>result;
        for(int i=0;i<n;i++){
            vector<int>visited(n,0);
            dfs(i,visited,adj);
            vector<int>ans;
            for(int j=0;j<n;j++){
                if(i!=j && visited[j]==1) ans.push_back(j);
            }
            result.push_back(ans);
            // cout<<i<<" "<<result.size()<<endl;
        }
        return result;
    }
};