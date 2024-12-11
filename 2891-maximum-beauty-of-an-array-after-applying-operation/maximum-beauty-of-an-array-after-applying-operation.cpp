class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxlen=0,j=0;
        for(int i=0;i<n;i++){
            while(j<n &&nums[j]-nums[i]<=2*k){
                j++;
            }
            maxlen=max(maxlen,j-i);
        }
        return maxlen;
    }
};