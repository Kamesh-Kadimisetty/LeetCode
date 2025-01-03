class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size(),splits=0;
        long long sum=0;
        long long total=accumulate(nums.begin(),nums.end(),0LL);
        for(int i=0;i<n-1;i++){
            sum+=nums[i];
            if(sum>=total-sum){
                splits++;
            }
        }
        return splits;
    }
};