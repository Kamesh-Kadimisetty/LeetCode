class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>outdegree(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                outdegree[i]++;
            }
        }
        queue<int>qu;
        vector<int>nodes(n,0);
        for(int i=0;i<n;i++){
            if(outdegree[i]==0){
                qu.push(i);
            }
        }
        while(!qu.empty()){
            int node=qu.front();
            qu.pop();
            nodes[node]=1;
            for(auto it:adj[node]){
                outdegree[it]--;
                if(outdegree[it]==0){
                    qu.push(it);
                }
            }
        }
        vector<int>result;
        for(int i=0;i<n;i++){
            if(nodes[i]==1){
                result.push_back(i);
            }
        }
        return result;
    }
};