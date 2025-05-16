class Solution {
public:
    bool distance(string s1,string s2){
        if(s1.size()!=s2.size()) return false;
        int cnt=0;
        for(int i=0;i<s1.size();i++){
            cnt+=s1[i]!=s2[i];
            if(cnt>1)return false;
        }
        return cnt==1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size(),maxind=0;
        vector<int>dp(n,1);
        vector<int>prev(n,-1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(distance(words[i],words[j]) && groups[i]!=groups[j] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
            if(dp[i]>dp[maxind]) maxind=i;
        }
        vector<string>result;
        for(int i=maxind;i>=0;i=prev[i]){
            result.push_back(words[i]);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};