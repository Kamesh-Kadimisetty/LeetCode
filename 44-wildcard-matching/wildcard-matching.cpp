class Solution {
public:
    bool func(int i,int j,string &s,string &p,vector<vector<int>>& dp){
        if(i==0 && j==0) return true;
        if(i==0){
            for(int k=1;k<=j;k++)
                if(p[k-1]!='*') return false;
            return true;
        }
        if(j==0 || i==0) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==p[j-1] || p[j-1]=='?'){
            if(func(i-1,j-1,s,p,dp)==true) return dp[i][j]=true;
        }
        if(p[j-1]=='*'){
            if((func(i-1,j,s,p,dp) || func(i,j-1,s,p,dp)) ==true) return dp[i][j]=true; 
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return func(n,m,s,p,dp);
    }
};