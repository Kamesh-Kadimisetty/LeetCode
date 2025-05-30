class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>after(n+1,0),curr(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){
                int len=after[prev+1];
                if(prev==-1 || nums[ind]>nums[prev]){
                    len=max(len,1+after[ind+1]);
                }
                curr[prev+1]=len;
            }
            after=curr;
        }
        return after[0];
    }
};