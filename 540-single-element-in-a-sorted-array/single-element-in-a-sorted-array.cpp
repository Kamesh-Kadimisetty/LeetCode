class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        //trimming first and last element and check them
        int low=1,high=n-2;
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        while(low<=high){
            int mid=(low+high)/2;
            //base case 
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            //eliminate left half(if mid is odd check for before even index or if mid is even check for next odd index)
            if((mid%2==1 && nums[mid-1]==nums[mid])||
                mid%2==0 && nums[mid]==nums[mid+1]){
                    low=mid+1;
            }
            //eliminate right half
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};