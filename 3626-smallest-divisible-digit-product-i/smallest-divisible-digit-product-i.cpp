class Solution {
public:
    bool isdivisible(int n,int t){
        int ans=1;
        while(n>0){
            int ind=n%10;
            ans=ans*ind;
            n=n/10;
        }
        return ans%t==0?true:false;
    }
    int smallestNumber(int n, int t) {
        if(n==t) return n;
        for(int i=n;i<INT_MAX;i++){
            if(isdivisible(i,t)){
                return i;
            }
        }
        return 0;
    }
};