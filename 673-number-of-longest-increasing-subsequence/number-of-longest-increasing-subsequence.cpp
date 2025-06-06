class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),cnt(n,1);
        int maxlen=1,maxcnt=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    cnt[i]=cnt[j];
                }
                else if(nums[i]>nums[j] && dp[i]==dp[j]+1) cnt[i]+=cnt[j];
            }
            maxlen=max(maxlen,dp[i]);
        }
        for(int i=0;i<n;i++){
            if(dp[i]==maxlen) maxcnt+=cnt[i];
        }
        for(auto it:dp) cout<<it<<" ";
        cout<<endl;
        for(auto it:cnt) cout<<it<<" ";
        return maxcnt;
    }
};