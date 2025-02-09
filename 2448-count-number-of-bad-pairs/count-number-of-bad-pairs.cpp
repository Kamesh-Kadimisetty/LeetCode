class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count=0;
        long long n=nums.size();
        long long total=(n*(n-1))/2;
        long long good=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            int val=nums[i]-i;
            if(mpp.find(val)!=mpp.end()){
                good+=mpp[val];
            }
            mpp[val]++;
        }
        return total-good;
    }
};