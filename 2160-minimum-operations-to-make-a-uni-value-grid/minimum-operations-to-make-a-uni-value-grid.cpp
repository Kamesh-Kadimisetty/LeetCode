class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>nums;
        int rem=grid[0][0]%x;
        for(auto it:grid){
            for(auto k:it){
                if(k%x!=rem)return -1;
                nums.push_back(k);
            }
        }
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans=0;
        if(n==1)return 0;
        int median=nums[(n/2)];
        for(auto it:nums){
            int diff=abs(median-it);
            ans+=diff/x;
        }
        return ans;
    }
};