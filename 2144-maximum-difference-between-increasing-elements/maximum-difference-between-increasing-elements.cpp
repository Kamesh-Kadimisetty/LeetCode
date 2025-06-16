class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size(),maxdiff=-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]<nums[j]) maxdiff=max(maxdiff,nums[j]-nums[i]);
            }
        }
        return maxdiff;
    }
};