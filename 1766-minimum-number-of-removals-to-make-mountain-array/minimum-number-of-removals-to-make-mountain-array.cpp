class Solution {
public:
    vector<int>lis(vector<int>nums){
        int n=nums.size();
        vector<int>dp(n,1);
        dp[0]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[j]+1,dp[i]);
                }
            }
        }
        return dp;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>increasing=lis(nums);  //LIS
        reverse(nums.begin(),nums.end());
        vector<int>decreasing=lis(nums);  //LDS
        reverse(decreasing.begin(),decreasing.end());
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(increasing[i]>1&&decreasing[i]>1){
                ans=min(ans,n-increasing[i]-decreasing[i]+1);
            }
        }
        return ans;
    }
};