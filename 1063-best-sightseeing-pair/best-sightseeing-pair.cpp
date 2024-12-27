class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int>leftmax(n);
        int maxscore=0;
        leftmax[0]=values[0];
        for(int i=1;i<n;i++){
            int curright=values[i]-i;
            maxscore=max(maxscore,leftmax[i-1]+curright);
            int currleft=values[i]+i;
            leftmax[i]=max(leftmax[i-1],currleft);
        }
        return maxscore;
    }
};