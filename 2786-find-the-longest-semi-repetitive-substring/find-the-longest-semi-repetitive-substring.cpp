class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n=s.size(),maxlen=0,i=0,j=1,last=0;
        if(n==1) return 1;
        while(j<n){
            if(s[j-1]==s[j]){
                i=last;
                last=j;
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};