class Solution {
public:
    bool hasSameDigits(string s) {
        int n=s.size();
        int cnt=0;
        while(s.size()>=3){
            cnt++;
            string st="";
            for(int i=0;i<s.size()-1;i++){
                char ch1=s[i];
                char ch2=s[i+1];
                int ch=(ch1-'0'+ch2-'0')%10;
                char ch3=ch+'0';
                st+=ch3;
            }
            s=st;
        }
        return s[0]==s[1];
    }
};