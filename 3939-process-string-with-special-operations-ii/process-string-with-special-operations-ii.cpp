class Solution {
public:
    char processStr(string s, long long k) {
        long long len=0;
        for(auto it:s){
            if(it=='*' && len>0) len--;
            else if(it=='#') len*=2;
            else if(islower(it)) len++;
        }
        if(k>=len) return '.';
        for(int i=s.size()-1;i>=0;i--){
            char ch=s[i];
            if(islower(ch)){
                if(k==len-1) return ch;
                len--;
            }
            else if(ch=='*'){
                len++;
            }
            else if(ch=='#'){
                len/=2;
                if(k>=len) k-=len;
            }
            else if(ch=='%'){
                k=len-k-1;
            }
        }
        return '.';
    }
};