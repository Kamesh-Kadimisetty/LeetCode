class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedboxes, vector<int>& initialboxes) {
        int n=status.size(),result=0;
        queue<int>qu;
        vector<int>havebox(n,0);
        for(auto it:initialboxes){
            if(status[it]==1) qu.push(it);
            else havebox[it]=1;
        }
        while(!qu.empty()){
            int x=qu.front();
            result+=candies[x];
            qu.pop();
            for(auto k:keys[x]){
                if(status[k]==0 && havebox[k]==1) qu.push(k);
                status[k]=1;
            }
            for(auto it:containedboxes[x]){
                if(status[it]==1) qu.push(it);
                else havebox[it]=1;
            }
        }
        return result;
    }
};