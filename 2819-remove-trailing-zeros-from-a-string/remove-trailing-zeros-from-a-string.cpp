class Solution {
public:
    string removeTrailingZeros(string num) {
        int n=num.size(),i=n-1;
        while(i>=0 && num[i]=='0'){
            i--;
        }
        string res;
        for(int j=0;j<i+1;j++){
            res+=num[j];
        }
        return res;
    }
};