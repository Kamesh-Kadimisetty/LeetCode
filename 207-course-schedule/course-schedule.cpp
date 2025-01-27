class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>result;
        while(!q.empty()){
            int course=q.front();
            q.pop();
            result.push_back(course);
            for(auto it:adj[course]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return result.size()==numCourses;
    }
};