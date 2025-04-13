class Solution {
public:
    int MOD=1e9+7;
    long long power(long long x,long long n){
        if(n==0) return 1;
        long long res=power(x,n/2);
        res=(res*res)%MOD;
        if(n%2==1){
            res=(res*x)%MOD;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long odd=n/2,even=n/2+n%2;
        return (power(4,odd)*power(5,even))%MOD;
    }
};