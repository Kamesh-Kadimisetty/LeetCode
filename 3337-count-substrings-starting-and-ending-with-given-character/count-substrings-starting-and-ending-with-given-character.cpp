class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long n=s.size(),freq=0,cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]==c){
                freq++;
                cnt+=freq;
            }
        }
        return cnt;
    }
};