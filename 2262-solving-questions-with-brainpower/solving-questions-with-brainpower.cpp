class Solution {
public:
    long long func(int ind,vector<vector<int>>& questions,vector<long long>&dp){
        int n=questions.size();
        if(ind>n-1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int points=questions[ind][0],next=questions[ind][1];
        long long pick=points+func(ind+next+1,questions,dp);
        long long notpick=func(ind+1,questions,dp);
        return dp[ind]=max(pick,notpick);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n+1,-1);
        return func(0,questions,dp);
    }
};