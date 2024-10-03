class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(),nums.end(),0LL); 
        if (sum % p == 0) return 0;
        int rem = sum % p;
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        long long prefixsum = 0; 
        int minlen = n;
        for (int i = 0; i < n; i++) {
            prefixsum = (prefixsum + nums[i]) % p; 
            int target = (prefixsum - rem + p) % p;
            if (mpp.find(target) != mpp.end()) {
                minlen = min(minlen, i - mpp[target]);
            }
            mpp[prefixsum] = i;
        }
        return minlen == n ? -1 : minlen;
    }
};
