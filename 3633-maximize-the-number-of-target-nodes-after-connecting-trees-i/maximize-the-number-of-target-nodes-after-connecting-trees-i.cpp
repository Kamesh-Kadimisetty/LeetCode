class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& visited,int k){
        visited[node]=1;
        for(auto it:adj[node]){
            if(k>0 && !visited[it]){
                dfs(it,adj,visited,k-1);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        vector<int>result(n);
        vector<vector<int>>adj1(n),adj2(m);
        for(auto it:edges1){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        for(auto it:edges2){
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }
        int maxele=0;
        if(k>0){
            for(int i=0;i<m;i++){
                vector<int>visited(m,0);
                dfs(i,adj2,visited,k-1);
                int x=0;
                for(auto it:visited) if(it==1) x++;
                maxele=max(maxele,x);
            }
        }
        for(int i=0;i<n;i++){
            vector<int>visited(n,0);
            dfs(i,adj1,visited,k);
            int x=0;
            for(auto it:visited) if(it==1) x++;
            result[i]=x+maxele;
        }
        return result;
    }
};