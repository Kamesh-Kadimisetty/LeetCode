class Solution {
public:
    long long lower_bound(vector<int>nums,int value){
        int n=nums.size();
        int low=0,high=n-1;
        long long ans=0;
        while(low<high){
            int sum=nums[low]+nums[high];
            if(sum<value){
                ans+=(high-low);
                low++;
            }
            else{
                high--;
            }
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return lower_bound(nums,upper+1)-lower_bound(nums,lower);
    }
};