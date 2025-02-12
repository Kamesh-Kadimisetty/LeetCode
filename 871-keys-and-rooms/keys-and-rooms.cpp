class Solution {
public:
    void dfs(int r,vector<vector<int>>&rooms,vector<int>&visited,int &total){
        total++;
        visited[r]=1;
        for(auto it:rooms[r]){
            if(!visited[it]){
                dfs(it,rooms,visited,total);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>visited(n,0);
        int totalrooms=0;
        dfs(0,rooms,visited,totalrooms);
        return totalrooms==n;
    }
};