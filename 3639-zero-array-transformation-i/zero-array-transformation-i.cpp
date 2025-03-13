class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>diff(n+1);
        diff[0]=nums[0];
        for(int i=1;i<n;i++){
            diff[i]=nums[i]-nums[i-1];
        }
        for(auto it:queries){
            int l=it[0],r=it[1];
            diff[l]-=1;
            diff[r+1]+=1;
        }
        nums[0]=diff[0];
        for(int i=1;i<n;i++){
            nums[i]=nums[i-1]+diff[i];
        }
        for(auto it:nums){
            if(it>0)return false;
        }
        return true;
    }
};