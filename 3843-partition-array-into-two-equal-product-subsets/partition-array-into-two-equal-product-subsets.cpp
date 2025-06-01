class Solution {
public:
    bool func(int ind,long mul,vector<int>&nums,long target){
        if(mul==target) return true;
        if(ind>=nums.size() || mul>target) return false;
        if(func(ind+1,mul,nums,target) || func(ind+1,mul*nums[ind],nums,target)==true){
            return true;
        }
        return false;
    }
    bool checkEqualPartitions(vector<int>& nums, long double target) {
        long double mult=1;
        int n=nums.size();
        for(auto it:nums) mult*=it;
        if(mult!=target*target) return false;
        return func(0,1,nums,target);
    }
};