class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxlen=1,n=nums.size(),len=1;
        if(n==1)return 1;
        int inc=nums[0]<nums[1]?1:0;
        if(nums[0]==nums[1] && n>2){
            inc=nums[1]<nums[2]?1:0;
        }
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i] && inc==1){
                len++;
            }
            else if(nums[i-1]<nums[i] && inc==0){
                maxlen=max(len,maxlen);
                inc=1;
                len=2;
            }
            else if(nums[i-1]>nums[i] && inc==0){
                len++;
            }
            else if(nums[i-1]>nums[i] && inc==1){
                maxlen=max(len,maxlen);
                inc=0;
                len=2;
            }
            else{
                maxlen=max(len,maxlen);
                len=1;
            }
        }
        maxlen=max(maxlen,len);
        return maxlen;
    }
};