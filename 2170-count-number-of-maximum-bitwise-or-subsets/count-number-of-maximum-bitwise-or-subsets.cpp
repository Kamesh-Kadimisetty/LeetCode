class Solution {
public:
    int func(int ind,int curr,vector<int>&nums,int ans){
        if(ind==nums.size()){
            return curr==ans?1:0;
        }
        return func(ind+1,curr|nums[ind],nums,ans)+func(ind+1,curr,nums,ans);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        for(int i=1;i<n;i++){
            ans=ans|nums[i];
        }
        return func(0,0,nums,ans);
    }
};