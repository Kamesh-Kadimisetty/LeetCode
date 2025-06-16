class Solution {
public:
    // bool func(string curr,int ind,string s,unordered_set<string>&st){
    //     if(ind==s.size()){
    //         if(st.find(curr)!=st.end() || curr=="") return true;
    //         return false;
    //     }
    //     if(st.find(curr)!=st.end()){
    //         string newcurr;
    //         if(func(newcurr+s[ind],ind+1,s,st)==true) return true; 
    //     }
    //     return func(curr+s[ind],ind+1,s,st);
    // }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        vector<bool>dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    string word=s.substr(j,i-j);
                    if(st.find(word)!=st.end()){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};