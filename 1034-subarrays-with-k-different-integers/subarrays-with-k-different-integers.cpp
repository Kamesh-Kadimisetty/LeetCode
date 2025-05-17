class Solution {
public:
    int cntsubarray(vector<int>& nums,int k){
        int n=nums.size(),cnt=0,i=0,j=0;
        unordered_map<int,int>mpp;
        while(j<n){
            mpp[nums[j]]++;
            while(mpp.size()>k){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                i++;
            }
            if(mpp.size()<=k) cnt+=j-i;
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k){
        return cntsubarray(nums,k)-cntsubarray(nums,k-1);
    }
};