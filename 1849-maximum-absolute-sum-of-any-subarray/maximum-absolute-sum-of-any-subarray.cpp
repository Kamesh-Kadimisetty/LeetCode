class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int maxval=0,minval=0,val=0;
        for(int i=0;i<n;i++){
            val+=nums[i];
            maxval=max(maxval,val);
            if(val<0){
                val=0;
            }
        }
        val=0;
        for(int i=0;i<n;i++){
            val+=nums[i];
            minval=min(minval,val);
            if(val>0){
                val=0;
            }
        }
        return max(maxval,abs(minval));
    }
};