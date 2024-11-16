class Solution {
public:
    int powerarr(vector<int>nums){
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]+1){
                return -1;
            }
        }
        return nums[nums.size()-1];
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res(n-k+1);
        for(int i=0;i<n-k+1;i++){
            vector<int>subvec(nums.begin()+i,nums.begin()+i+k);
            res[i]=powerarr(subvec);
        }
        return res;
    }
};