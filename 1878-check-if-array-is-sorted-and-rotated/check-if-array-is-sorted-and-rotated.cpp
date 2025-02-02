class Solution {
public:
    bool check(vector<int>& nums) {
        int flag=0,n=nums.size(),choice=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                if(choice==1){
                    choice--;
                }
                else{
                    return false;
                }
            }
        }
        if(choice==0){
            return nums[0]>=nums[n-1];
        }
        return true;
    }
};