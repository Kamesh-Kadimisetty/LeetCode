class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>result;
        queue<pair<int,vector<int>>>qu;
        vector<int>nodes={0};
        qu.push({0,nodes});
        while(!qu.empty()){
            int node=qu.front().first;
            vector<int>arr=qu.front().second;
            qu.pop();
            if(node==n-1) result.push_back(arr);
            for(auto it:graph[node]){
                arr.push_back(it);
                qu.push({it,arr});
                arr.pop_back();
            }
        }
        return result;
    }
};