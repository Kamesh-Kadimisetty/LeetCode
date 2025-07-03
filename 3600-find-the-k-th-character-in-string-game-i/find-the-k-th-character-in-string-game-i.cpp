class Solution {
public:
    string func(string s){
        int n=s.size();
        for(int i=0;i<n;i++){
            s+=(s[i]-'a'+1+26)%26+'a';
        }
        return s;
    }
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<k){
            s=func(s);
        }
        return s[k-1];
    }
};