class Solution {
public:
    int func(int i,int j,string s){
        if(i<0 || j>=s.size()) return 0;
        if(s[i]==s[j]){
            return 1+func(i-1,j+1,s);
        }
        return 0;
    }
    string longestPalindrome(string s) {
        int n=s.size(),maxsize=0;
        string result;
        for(int i=0;i<n;i++){
            int x=func(i-1,i+1,s);
            if(2*x+1>maxsize){
                maxsize=2*x+1;
                result=s.substr(i-x,maxsize);
            }

            int y=func(i,i+1,s);
            if(2*y>maxsize){
                maxsize=2*y;
                result=s.substr(i-y+1,maxsize);
            }
        }
        return result;
    }
};