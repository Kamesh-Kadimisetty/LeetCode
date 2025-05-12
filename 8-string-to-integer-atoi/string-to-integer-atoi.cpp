class Solution {
public:
    int myAtoi(string s) {
        int n=s.size(),flag=0,i=0;
        while(s[i]==' ' && i<n){
            i++;
        }
        if(s[i]=='-'){
            flag=1;
            i++;
        }
        else if(s[i]=='+') i++;
        while(s[i]=='0' && i<n) i++;
        vector<int>arr;
        while(s[i]>='0' && s[i]<='9' && i<n){
            arr.push_back(s[i]-'0');
            i++;
        }
        if(arr.size()>11) return flag==1?-2147483648:2147483647;
        long long num=0,mul=1;
        for(int i=arr.size()-1;i>=0;i--){
            num=(arr[i]*mul)+num;
            mul*=10;
            if(num>2147483647) return flag==1?-2147483648:2147483647;
        }
        return flag==1?(-1*num):num;
    }
};