class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n=s.size(),maxlen=0,prev=0;
        if(n==1) return 1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i+1;j<n;j++){
                if(s[j]==s[j-1]) cnt++;
                if(cnt==2) break;
                maxlen=max(maxlen,j-i+1);
            }
        }
        return maxlen;
    }
};