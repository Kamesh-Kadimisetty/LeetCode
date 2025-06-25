class Solution {
public:
    int func(vector<int>&nums,long long num,long long maxlimit){
        int low=0,high=nums.size()-1;
        while(low<=high){
            long long mid=(low+high)/2;
            if((num>=0 && nums[mid]*num<=maxlimit) || (num<0 && nums[mid]*num>maxlimit)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return num>=0?low:nums.size()-low;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n=nums1.size(),m=nums2.size();
        long long low=-1e10,high=1e10;
        while(low<=high){
            long long mid=(low+high)/2;
            long long cnt=0;
            //find numbers of pairs with product less than mid
            for(int i=0;i<n;i++){
                cnt+=func(nums2,nums1[i],mid);
            }
            if(cnt<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};