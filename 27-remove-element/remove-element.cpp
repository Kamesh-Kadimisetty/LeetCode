class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                res.push_back(nums[i]);
                k++;
            }
        }
        for(int i=0;i<res.size();i++){
            nums[i]=res[i];
        }
        return k;
    }
};