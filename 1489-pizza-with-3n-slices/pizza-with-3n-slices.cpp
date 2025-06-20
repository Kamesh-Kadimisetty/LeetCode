class Solution {
public:
    int func(int ind,int x,int n,vector<int>&slices,vector<vector<int>>&dp){
        if(x==0 || ind>n) return 0;
        if(dp[ind][x]!=-1) return dp[ind][x];
        return dp[ind][x]=max(slices[ind]+func(ind+2,x-1,n,slices,dp),func(ind+1,x,n,slices,dp));
    }
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size(),x=n/3;
        vector<vector<int>>dp1(n,vector<int>(x+1,-1));
        vector<vector<int>>dp2(n,vector<int>(x+1,-1));
        return max(func(0,x,n-2,slices,dp1),func(1,x,n-1,slices,dp2));
    }
};