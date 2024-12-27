class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int maxscore=0;
        int leftmax=values[0];
        for(int i=1;i<n;i++){
            int curright=values[i]-i;
            maxscore=max(maxscore,leftmax+curright);
            int currleft=values[i]+i;
            leftmax=max(leftmax,currleft);
        }
        return maxscore;
    }
};