class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st(nums.begin(),nums.end());
        int tot=st.size(),i=0,j=0,cnt=0;
        unordered_map<int,int>mpp;
        while(j<n){
            mpp[nums[j]]++;
            while(mpp.size()==tot && i<=j){
                cnt+=n-j;
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return cnt;
    }
};
