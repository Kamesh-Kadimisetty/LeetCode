class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans=0;
        int min_val=arrays[0].front();
        int max_val=arrays[0].back();
        for(int i=1;i<arrays.size();i++){
            ans=max(ans,max(abs(arrays[i].front()-max_val),abs(arrays[i].back()-min_val)));
            min_val=min(min_val,arrays[i].front());
            max_val=max(max_val,arrays[i].back());
        }
        return ans;
    }
};