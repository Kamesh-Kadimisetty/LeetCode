class Solution {
public:
    int maxScore(vector<int>& cardpoints, int k) {
        int n=cardpoints.size(),i=0,j=0;
        vector<int>presum(n+1,0);
        presum[0]=cardpoints[0];
        for(int i=1;i<n;i++){
            presum[i]=presum[i-1]+cardpoints[i];
        }
        int maxscore=0;
        for(int i=0;i<k;i++){
            maxscore=max(maxscore,presum[i]+presum[n-1]-presum[n-k+i]);
        }
        if(k!=n)maxscore=max(maxscore,presum[n-1]-presum[n-k-1]);
        return maxscore;
    }
};