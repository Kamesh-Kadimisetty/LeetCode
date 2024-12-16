class Solution {
public:
    int findmin(vector<int>nums){
        int ind=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<nums[ind]){
                ind=i;
            }
        }
        return ind;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int>result(nums);
        while(k--){
            int x=findmin(result);
            result[x]=multiplier*result[x];
        }
        return result;
    }
};