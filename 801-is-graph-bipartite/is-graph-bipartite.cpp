class Solution {
public:
    bool check(int start,vector<vector<int>>& graph,vector<int>color){
        queue<int>qu;
        qu.push(start);
        color[start]=0;
        while(!qu.empty()){
            int node=qu.front();
            qu.pop();
            for(auto it:graph[node]){
                int tobecolor=color[node]==1?0:1;
                if(color[it]==color[node]){
                    return false;
                }
                else if(color[it]==-1){
                    color[it]=tobecolor;
                    qu.push(it);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(check(i,graph,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};