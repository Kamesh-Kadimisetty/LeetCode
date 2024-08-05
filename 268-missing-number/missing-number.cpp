class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum1=n*(n+1)/2;
        return sum1-accumulate(nums.begin(),nums.end(),0);;
    }
};