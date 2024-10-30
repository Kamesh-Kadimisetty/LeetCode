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
     vector<int> lisoptimal(vector<int>nums)
    {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>helper;
        helper.push_back(nums[0]);
        int ind=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>helper[ind]) {
                ind++;
                helper.push_back(nums[i]);
            }
            else {
                putproper(nums[i],helper,ind);
            }
            dp[i]=ind+1;
        }
        return dp;
    }
    void putproper(int val,vector<int>&arr,int lastind) 
    {
        int start=0;
        int end=lastind;
        int mid;
        while(start<end)
        {
            mid=start+(end-start)/2;
            if(arr[mid]==val)
                return ;
            else if(arr[mid]>val)
                end=mid;
            else
                start=mid+1;
        }
        arr[start]=val;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>increasing=lisoptimal(nums);  //LIS
        reverse(nums.begin(),nums.end());
        vector<int>decreasing=lisoptimal(nums);  //LDS
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