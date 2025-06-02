class Solution {
public:
    bool func(string& s,string& t){
        int n=s.size(),m=t.size();
        if(n!=m+1) return false;
        int i=0,j=0,flag=0;
        while(i<n && j<m){
            if(s[i]!=t[j]){
                if(flag==0) flag=1;
                else return false;
                i++;
            }
            else{
                i++;
                j++;
            }
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),[](string &s,string &t){
            return s.size()<t.size();
        });
        vector<int>dp(n,1);
        int maxval=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(func(words[i],words[j]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
            maxval=max(maxval,dp[i]);
        }
        return maxval;
    }
};