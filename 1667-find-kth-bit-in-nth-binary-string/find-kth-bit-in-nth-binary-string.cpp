class Solution {
public:
    string func(string s){
        string si=s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                s[i]='0';
            }
            else{
                s[i]='1';
            }
        }
        reverse(s.begin(),s.end());
        si.append("1");
        si.append(s);
        return si;
    }
    char findKthBit(int n, int k) {
        string s="0";
        while(n>1){
            n--;
            s=func(s);
        }
        return s[k-1];
    }
};