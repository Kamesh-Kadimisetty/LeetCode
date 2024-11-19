class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int left=0;
        long maxsum=0,currsum=0;
        unordered_set<int>window;
        for(int right=0;right<nums.size();right++){
            while(window.count(nums[right])){
                window.erase(nums[left]);
                currsum-=nums[left];
                left++;
            }
            window.insert(nums[right]);
            currsum+=nums[right];
            if(right-left+1==k){
                maxsum=max(maxsum,currsum);
                window.erase(nums[left]);
                currsum-=nums[left];
                left++;
            }
        }
        return maxsum;
    }
};