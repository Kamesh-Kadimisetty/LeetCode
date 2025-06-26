class Solution {
public:
    // int result=0;
    // int todecimal(string num){
    //     int ans=0,pow=0;
    //     for(int i=num.size()-1;i>=0;i--){
    //         if(num[i]=='1') ans+=(1<<pow);
    //         pow++;
    //     }
    //     return ans;
    // }
    // void func(int ind,string str,string &s,int k){
    //     if(ind==s.size()){
    //         if(todecimal(str)<=k) result=max(result,int(str.size()));
    //         return;
    //     }
    //     func(ind+1,str+s[ind],s,k);
    //     func(ind+1,str,s,k);
    // }
    int longestSubsequence(string s, int k) {
        long long n=s.size(),len=0,sum=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1' && sum<=k){
                long double x=pow(2,len);
                if(sum+x<=k){
                    len++;
                    sum+=x;
                }
            }
            if(s[i]=='0'){
                len++;
            }
        }
        return len;
    }
};