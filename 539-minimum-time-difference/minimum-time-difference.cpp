class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        vector<int>timemin;
        int mindif=INT_MAX;
        for(int i=0;i<timePoints.size();i++){
            timemin.push_back((stoi(timePoints[i].substr(0,2))*60)+stoi(timePoints[i].substr(3,2)));
            cout<<timemin[i]<<" ";
        }
        int n=timemin.size();
        for(int i=0;i<n-1;i++){
            int diff=timemin[i+1]-timemin[i];
            if(diff>720){
                diff=abs(timemin[i+1]-1440-timemin[i]);
            }
            mindif=min(mindif,diff);
        }
        int diff=timemin[n-1]-timemin[0];  
        if(diff>720){
                diff=abs(timemin[n-1]-1440-timemin[0]);
            }
        mindif=min(mindif,diff);    
        return mindif;
    }
};