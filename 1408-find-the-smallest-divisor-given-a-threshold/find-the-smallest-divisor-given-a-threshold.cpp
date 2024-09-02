class Solution {
public:
    int smalldiv(vector<int> &nums,int mid){
        int threshold=0;
        for(int i=0;i<nums.size();i++){
            threshold+=ceil(double(nums[i])/double(mid));
        }
        return threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(smalldiv(nums,mid)<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};