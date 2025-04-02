class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result=0;
        int n=nums.size();
        for(int k=2;k<n;k++){
            int maxi=nums[0];
            for(int j=1;j<k;j++){
                result=max(result,(long long)(maxi-nums[j])*nums[k]);
                maxi=max(maxi,nums[j]);

            }
        }
        return result;
    }
};