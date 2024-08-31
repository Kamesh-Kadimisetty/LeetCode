class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            ans = min(ans, nums[mid]);
            ans = min(ans, nums[low]);
            ans = min(ans, nums[high]);
            
            // Determine which part of the array to explore
            if (nums[low] < nums[mid]) {
                // The minimum is in the right half
                low = mid + 1;
            } else if (nums[mid] < nums[high]) {
                // The minimum is in the left half
                high = mid - 1;
            } else {
                // nums[low] == nums[mid] == nums[high], we need to reduce the search space
                low++;
                high--;
            }
        }
        return ans;
    }
};