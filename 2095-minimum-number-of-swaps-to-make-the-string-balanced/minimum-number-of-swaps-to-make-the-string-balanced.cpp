class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        if(n==0) return 0;
        int count=0,ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='['){
                count++;
            }
            else if(s[i]==']'){
                count--;
            }
            if(count<0){
                count=1;
                ans++;
            } 
        }
        return ans;
    }
};