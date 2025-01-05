class Solution {
public:
    char shift(char &ch,long long n){
        n=n%26;
        return (ch-'a'+n)%26+'a';
    }
    string shiftingLetters(string s, vector<int>& shifts) {
        string str=s;
        int n=shifts.size();
        long long cnt=0;
        for(int i=n-1;i>=0;i--){
            cnt+=shifts[i];
            str[i]=shift(str[i],cnt);
        }
        return str;
    }
};