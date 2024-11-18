class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>result(n,0);
        if(k==0)return result;
        for(int i=0;i<n;i++){
            int sum=0;
            if(k>0){
                int t=i;
                for(int j=0;j<k;j++){
                    t=(t+1)%n;
                    sum+=code[t];
                }
                result[i]=sum;
            }
            if(k<0){
                int t=i;
                for(int j=0;j<abs(k);j++){
                    t=abs((t-1+n)%n);
                    sum+=code[t];
                }
                result[i]=sum;
            }
        }
        return result;
    }
};