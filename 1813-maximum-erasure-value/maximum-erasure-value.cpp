class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size(),sum=0,maxsum=0;
        unordered_map<int,int>mpp;
        int i=0,j=0;
        while(j<n){
            while(mpp.find(nums[j])!=mpp.end()){
                sum-=nums[i];
                mpp.erase(nums[i]);
                i++;
            }
            sum+=nums[j];
            mpp[nums[j]]=j;
            maxsum=max(maxsum,sum);
            j++;
        }
        return maxsum;
    }
};