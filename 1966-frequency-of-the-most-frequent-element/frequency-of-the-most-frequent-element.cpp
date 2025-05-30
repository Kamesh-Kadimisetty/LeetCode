class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        sort(nums.begin(),nums.end());
        for(auto it:nums) mpp[it]++;
        int maxfreq=mpp[nums[0]];
        for(int i=1;i<n;i++){
            int freq=mpp[nums[i]],x=k;
            if(nums[i]!=nums[i-1]){
                for(int j=i-1;j>=0 && x>0;j--){
                    x-=nums[i]-nums[j];
                    if(x>=0) freq++;
                }
            }
            maxfreq=max(maxfreq,freq);
        }
        return maxfreq;
    }
};