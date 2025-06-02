class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>hash(n);
        int maxind=-1,maxval=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i]>maxval){
                maxind=i;
                maxval=dp[i];
            }
        }
        vector<int>temp;
        while(hash[maxind]!=maxind){
            temp.push_back(nums[maxind]);
            maxind=hash[maxind];
        }
        temp.push_back(nums[maxind]);
        return temp;
    }
};