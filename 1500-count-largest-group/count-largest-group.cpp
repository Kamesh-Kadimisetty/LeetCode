class Solution {
public:
    int sumofdigits(int x){
        int sum=0;
        while(x>0){
            sum+=x%10;
            x/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int>mpp;
        int maxsize=0;
        for(int i=1;i<=n;i++){
            int k=sumofdigits(i);
            mpp[k]++;
            maxsize=max(maxsize,mpp[k]);
        }
        int cnt=0;
        for(auto it:mpp){
            if(it.second==maxsize)cnt++;
        }
        return cnt;
    }
};