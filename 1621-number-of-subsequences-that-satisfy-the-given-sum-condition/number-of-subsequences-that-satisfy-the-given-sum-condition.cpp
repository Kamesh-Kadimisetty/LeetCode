class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size(),cnt=0,MOD=1e9+7;
        sort(nums.begin(),nums.end());
        int low=0,high=n-1;
        vector<int>power(n,1);
        for(int i=1;i<n;i++){
            power[i]=(2*power[i-1])%MOD;
        }
        while(low<=high){
            if(nums[low]+nums[high]<=target){
                cnt=(cnt+power[high-low])%MOD;
                low++;
            }
            else{
                high--;
            }
        }
        return cnt;
    }
};