class Solution {
public:
    bool ispossible(vector<int>& nums, int k,int mid){
        int n=nums.size();
        int i=0;
        while(i<n){
            if(k==0)return true;
            if(nums[i]<=mid){
                k--;
                i+=2;
            }
            else{
                i++;
            }
        }
        return k==0;
    }
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(ispossible(nums,k,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};