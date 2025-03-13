class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>diff(n+1);
        for(auto it:queries){
            int l=it[0],r=it[1];
            diff[l]++;
            diff[r+1]--;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=diff[i];
            if(sum<nums[i])return false;
        }
        return true;
    }
};