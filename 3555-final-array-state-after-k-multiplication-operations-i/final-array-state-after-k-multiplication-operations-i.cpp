class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int>result(nums);
        while(k--){
            int ind=0;
            for(int i=0;i<result.size();i++){
                if(result[i]<result[ind]){
                    ind=i;
                }
            }
            result[ind]*=multiplier;
        }
        return result;
    }
};