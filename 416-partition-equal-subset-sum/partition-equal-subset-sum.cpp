class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        long long total=accumulate(nums.begin(),nums.end(),0LL);
        if(total%2!=0)return false;
        int target=total/2;
        vector<bool>dp(target+1,false);
        dp[0]=true;
        for(auto num:nums){
            for(int j=target;j>=num;j--){
                dp[j]=dp[j] || dp[j-num];
            }
        }
        return dp[target];
    }
};