class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        vector<long long >presum(n,chalk[0]);// prefix sum 0-indexed 
        for(int i=1;i<n;i++){
            presum[i]=chalk[i]+presum[i-1];
        }
        k%=presum[n-1];
        return upper_bound(presum.begin(),presum.end(),k)-presum.begin();
    }
};