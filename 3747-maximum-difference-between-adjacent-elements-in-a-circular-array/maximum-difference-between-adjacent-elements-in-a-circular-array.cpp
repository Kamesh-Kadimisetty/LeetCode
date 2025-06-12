class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int maxval=0;
        for(int i=0;i<n-1;i++){
            maxval=max(maxval,abs(nums[i]-nums[i+1]));
        }
        maxval=max(maxval,abs(nums[0]-nums[n-1]));
        return maxval;
    }
};