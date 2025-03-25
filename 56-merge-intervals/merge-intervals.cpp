class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>result;
        int start=intervals[0][0],end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int x=intervals[i][0],y=intervals[i][1];
            if(end>=x){
                end=max(end,y);
            }
            else{
                result.push_back({start,end});
                start=x;
                end=y;
            }
        }
        result.push_back({start,end});
        return result;
    }
};