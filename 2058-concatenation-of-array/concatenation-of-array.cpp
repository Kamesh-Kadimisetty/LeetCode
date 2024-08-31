class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        int k=0;
        while(k<2){
        for(int i=0;i<n;i++){
            ans.push_back(nums[i]);
        }
        k++;
        }
        return ans;
    }
};