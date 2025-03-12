class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<high){
            int mid=(low+high)/2;
            if(nums[mid]==0 || mid>0 && nums[mid-1]<0 && nums[mid]>0){
                break;
            }
            else if(nums[mid]>0){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        int ind=(low+high)/2;
        int pos=-1,neg=-1,i=ind;
        while(i>=0 && nums[i]>=0){
            i--;
        }
        while(ind<=n-1 && nums[ind]<=0){
            ind++;
        }
        neg=i+1;
        pos=n-ind;
        return max(pos,neg);
    }
};