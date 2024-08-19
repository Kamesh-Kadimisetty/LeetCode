class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        vector<int>prime;
        while(n%2==0){
            prime.push_back(2);
            n/=2;
        }
        for(int i=3;i*i<=n;i+=2){
            while(n%i==0){
                prime.push_back(i);
                n/=i;
            }
        }
        if(n>2){
            prime.push_back(n);
        }
        return accumulate(prime.begin(),prime.end(),0);
    }
};