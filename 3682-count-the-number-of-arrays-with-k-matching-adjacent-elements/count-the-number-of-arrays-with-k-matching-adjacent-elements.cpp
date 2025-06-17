int MOD=1e9+7;
class Solution {
public:
    long long power(long long base,long long exp){
        long long result=1;
        while(exp>0){
            if(exp%2==1){
                result=(result*base)%MOD;
            }
            base=(base*base)%MOD;
            exp/=2;
        }
        return result;
    }
    long long modinv(long long x){
        return power(x,MOD-2);
    }
    long long ncr(int n,int r,vector<long long>& fact){
        return fact[n]*modinv(fact[r])%MOD*modinv(fact[n-r])%MOD;
    }
    int countGoodArrays(int n, int m, int k) {
        vector<long long>fact(n+1,1);
        for(int i=2;i<=n;i++){
            fact[i]=(fact[i-1]*i)%MOD;
        }
        long long cnt=m;
        cnt=cnt*ncr(n-1,k,fact)%MOD;
        cnt=cnt*power(m-1,n-k-1)%MOD;
        return cnt;
    }
};