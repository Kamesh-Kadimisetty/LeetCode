class Solution {
public:
    int totalways=0;
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        calculateways(nums,0,0,target);
        return totalways;
    }
    void calculateways(vector<int>&nums,int ind,int currsum,int target){
        int n=nums.size();
        if(ind==n){
            if(currsum==target){
                totalways++;
            }
        }
        else{
            calculateways(nums,ind+1,currsum+nums[ind],target);
            calculateways(nums,ind+1,currsum-nums[ind],target);
        }
    }
};