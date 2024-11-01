class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size()<2) return true;
        int flag=nums[0]%2;
        for(int i=1;i<nums.size();i++){
            int rem=nums[i]%2;
            if(rem==flag){
                return false;
            }
            flag=rem;
        } 
        return true;
    }
};