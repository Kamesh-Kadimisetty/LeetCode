class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        set<int>st(nums.begin(),nums.end());
        unordered_map<int,int>mpp;
        long long result=LLONG_MIN;
        int n=nums.size(),i=0,j=m-1;
        for(auto it:nums) mpp[it]++;
        for(int k=0;k<m-1;k++){
            mpp[nums[k]]--;
            if(mpp[nums[k]]==0) st.erase(nums[k]);
        }
        while(j<n){
            int mini=*st.begin(),maxi=*st.rbegin();
            result=max(result,1LL*maxi*nums[i]);
            result=max(result,1LL*mini*nums[i]);
            i++;
            mpp[nums[j]]--;
            if(mpp[nums[j]]==0) st.erase(nums[j]);
            j++;
        }
        return result;
    }
};