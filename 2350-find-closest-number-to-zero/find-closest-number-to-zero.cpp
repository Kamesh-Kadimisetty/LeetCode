class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans=INT_MAX,res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int dist=abs(nums[i]);
            if(ans>=dist){
            ans=dist;
            res=nums[i];
            }
            
        }
        return res;
    }
};