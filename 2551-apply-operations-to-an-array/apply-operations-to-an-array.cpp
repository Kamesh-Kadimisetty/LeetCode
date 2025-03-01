class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int>result;
        int k=0,n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1] && nums[i]!=0){
                result.push_back(2*nums[i]);
                nums[i+1]=0;
            }
            else if(nums[i]!=0){
                result.push_back(nums[i]);
            }
        }
        result.push_back(nums[n-1]);
        for(int i=result.size();i<n;i++){
            result.push_back(0);
        }
        return result;
    }
};