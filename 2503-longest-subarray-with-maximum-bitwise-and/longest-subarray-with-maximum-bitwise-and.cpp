class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size(),maxlen=0,currentlen=0;
        int maxvalue=*max_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]==maxvalue){
                currentlen++;
            }
            else{
                maxlen=max(maxlen,currentlen);
                currentlen=0;
            }
        }
        maxlen=max(maxlen,currentlen);
        return maxlen;
    }
};