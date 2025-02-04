class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size(),maxsum=nums[0],currsum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                currsum+=nums[i];
            }
            else{
                currsum=nums[i];
            }
            maxsum=max(maxsum,currsum);
        }
        return maxsum;
    }
};