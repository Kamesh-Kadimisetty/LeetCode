class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long n=nums.size(),ans=0,j=0,cnt=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            while(cnt<k && j<n){
                cnt+=mpp[nums[j]];
                mpp[nums[j]]++;
                j++;
            }
            if(cnt>=k){
                ans+=n-j+1;
            }
            cnt-=(mpp[nums[i]]-1);
            mpp[nums[i]]--;
        }
        return ans;
    }
};