class Solution {
public:
    char shift(char &ch,long long n){
        n=n%26;
        return (ch-'a'+n+26)%26+'a';
    }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>count(n,0);
        for(auto sh:shifts){
            int start=sh[0],end=sh[1],dir=sh[2];
            int change=(dir==1)?1:-1;
            count[start]+=change;
            if(end+1<n){
                count[end+1]-=change;
            }
        }
        for(int i=1;i<n;i++){
            count[i]+=count[i-1];
        }
        for(int i=0;i<n;i++){
            s[i]=shift(s[i],count[i]);
        }
        return s;
    }
};