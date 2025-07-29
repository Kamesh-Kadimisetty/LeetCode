class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>near(32,-1),result(n);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<32;j++){
                if(nums[i]&(1<<j)){
                    near[j]=i;
                }
            }
            int lastset=i;
            for(auto it:near) lastset=max(lastset,it);
            result[i]=lastset-i+1;
        }
        return result;
    }
};