class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int reach=0;
        for(int i=0;i<n;i++){
            if(i<=reach){
                reach=max(reach,i+nums[i]);
            }
            else{
                break;
            }
        }
        return reach>=n-1;
    }
};