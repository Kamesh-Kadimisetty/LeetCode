class Solution {
public:
    int rob(vector<int>& nums){
        int n=nums.size();
        int prev2=0;
        int prev=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i];
            int notpick=0+prev;
            if(i>1){
                pick+=prev2;
            }
            int curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};