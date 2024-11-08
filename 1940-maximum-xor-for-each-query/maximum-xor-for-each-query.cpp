class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int kmax=pow(2,maximumBit)-1;
        int n=nums.size();
        vector<int>answer;
        int val=0;
        for(auto num:nums){
            val=val^num;
            answer.push_back(kmax^val);
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};

