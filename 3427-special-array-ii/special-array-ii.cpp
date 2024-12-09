class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>converted(1,0);
        vector<bool>ans;
        int j=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]%2==nums[i-1]%2){
                j++;
            }
            converted.push_back(j);
        }
        for(auto q:queries){
            ans.push_back(converted[q[0]]==converted[q[1]]);
        }
        return ans;
    }
};