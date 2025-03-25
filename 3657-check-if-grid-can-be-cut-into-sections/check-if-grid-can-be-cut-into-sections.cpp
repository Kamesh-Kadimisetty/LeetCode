class Solution {
public:
    int merge(vector<pair<int,int>>& intervals){
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>result;
        int start=intervals[0].first,end=intervals[0].second;
        for(int i=1;i<intervals.size();i++){
            int x=intervals[i].first,y=intervals[i].second;
            if(end>x){
                end=max(end,y);
            }
            else{
                result.push_back({start,end});
                start=x;
                end=y;
            }
        }
        result.push_back({start,end});
        return result.size();
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> xaxis;
        vector<pair<int,int>> yaxis;
        for(auto it:rectangles){
            xaxis.push_back({it[0],it[2]});
            yaxis.push_back({it[1],it[3]});
        }
        sort(xaxis.begin(),xaxis.end());
        sort(yaxis.begin(),yaxis.end());
        int ans=merge(xaxis);
        ans=max(ans,merge(yaxis));
        return ans>=3;
    }
};