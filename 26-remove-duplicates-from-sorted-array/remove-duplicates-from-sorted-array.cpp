class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans=nums[0],k=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=ans){
                ans=nums[i];
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};