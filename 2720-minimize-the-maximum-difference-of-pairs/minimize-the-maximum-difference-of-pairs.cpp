class Solution{
public:
    int func(vector<int>&nums,int range){
        int pairs=0,i=0;
        while(i<nums.size()-1){
            if(nums[i+1]-nums[i]<=range){
                pairs++;
                i+=2;
            }
            else{
                i++;
            }
        }
        return pairs;
    }
    int minimizeMax(vector<int>& nums, int p){
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0,high=nums[n-1]-nums[0];
        while(low<high){
            int mid=(low+high)/2;
            if(func(nums,mid)>=p){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};