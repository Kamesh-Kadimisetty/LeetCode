class Solution {
public:
    bool dfs(int start,vector<vector<int>>& graph,vector<int>&color,int col){
        color[start]=col;
        int tocol=col==0?1:0;
        for(auto it:graph[start]){
            if(color[it]==-1){
                if(dfs(it,graph,color,tocol)==false) return false;
            }
            if(color[it]==col){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,graph,color,0)==false){
                    return false;
                }
            }
        }
        return true;
    }
};