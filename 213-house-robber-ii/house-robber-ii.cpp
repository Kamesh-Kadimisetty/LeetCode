class Solution {
public:
    int rob1(vector<int>& nums){
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
    int rob(vector<int>& nums) {
        vector<int>temp1,temp2;
        int n=nums.size();
        if(n==1)return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        return max(rob1(temp1),rob1(temp2));
    }
};