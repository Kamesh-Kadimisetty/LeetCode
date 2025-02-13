class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int>qu;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                qu.push(i);
            }
        }
        vector<int>result;
        while(!qu.empty()){
            int node=qu.front();
            qu.pop();
            result.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    qu.push(it);
                }
            }
        }
        if(result.size()!=numCourses){
            return {};
        }
        reverse(result.begin(),result.end());
        return result;
    }
};