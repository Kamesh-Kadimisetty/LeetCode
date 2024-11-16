class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (nums.empty() || k > nums.size()){
            return {};
        }
        int n=nums.size();
        vector<int>res(n-k+1);
        //sliding window
        for(int i=0;i<n-k+1;i++){
            bool isconsecutive=true;
            for(int j=i+1;j<i+k;j++){
                if(nums[j]!=nums[j-1]+1){
                    isconsecutive=false;
                    break;
                }
            }
            res[i]=isconsecutive?nums[i+k-1]:-1;
        }
        return res;
    }
};