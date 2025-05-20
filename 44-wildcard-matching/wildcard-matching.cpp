class Solution {
public:
    bool func(int i,int j,string &s,string &p,vector<vector<int>>& dp){
        if(i<0 && j<0) return true;
        if(i<0){
            for(int k=0;k<=j;k++)
                if(p[k]!='*') return false;
            return true;
        }
        if(j<0 || i<0) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?'){
            if(func(i-1,j-1,s,p,dp)==true) return dp[i][j]=true;
        }
        if(p[j]=='*'){
            if((func(i-1,j,s,p,dp) || func(i,j-1,s,p,dp)) ==true) return dp[i][j]=true; 
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(n-1,m-1,s,p,dp);
    }
};