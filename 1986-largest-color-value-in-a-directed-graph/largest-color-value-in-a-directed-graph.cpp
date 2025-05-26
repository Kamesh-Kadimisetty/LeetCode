class Solution {
public:
    int dfs(int node,string &colors,vector<vector<int>>&adj,vector<int>&visited,vector<vector<int>>&count){
        if(!visited[node]){
            visited[node]=1;
            for(auto it:adj[node]){
                if(dfs(it,colors,adj,visited,count)==INT_MAX) return INT_MAX;
                for(int c=0;c<26;c++){
                    count[node][c]=max(count[node][c],count[it][c]);
                }
            }
            count[node][colors[node]-'a']++;
            visited[node]=2;
        }
        return visited[node]==2?count[node][colors[node]-'a']:INT_MAX;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>>adj(n);
        vector<vector<int>>count(n,vector<int>(26));
        vector<int>visited(n,0);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
        }
        int ans=0;
        for(int i=0;i<n && ans!=INT_MAX;i++){
            ans=max(ans,dfs(i,colors,adj,visited,count));
        }
        return ans==INT_MAX?-1:ans;
    }
};