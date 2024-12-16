class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int x=target[0],y=target[1];
        int targetsteps=abs(x)+abs(y);
        vector<int>ghoststeps;
        for(auto it:ghosts){
            if(targetsteps>=(abs(x-it[0])+abs(y-it[1]))){
                return false;
            }
        }
        return true;
    }
};