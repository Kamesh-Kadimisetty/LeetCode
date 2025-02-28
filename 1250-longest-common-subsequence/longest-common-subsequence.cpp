class Solution {
public:
    int func(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        if(i==s1.size() || j==s2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j]=1+func(s1,s2,i+1,j+1,dp);
        }
        else{
            return dp[i][j]=max(func(s1,s2,i,j+1,dp),func(s1,s2,i+1,j,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(text1,text2,0,0,dp);
    }
};