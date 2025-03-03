class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int lesser=0,equal=0;
        for(auto it:nums){
            if(it<pivot){
                lesser++;
            }
            else if(it==pivot){
                equal++;
            }
        }
        vector<int>res(nums.size());
        int less=0,same=lesser,greater=lesser+equal;
        for(auto it:nums){
            if(it==pivot){
                res[same++]=it;
            }
            else if(it<pivot){
                res[less++]=it;
            }
            else{
                res[greater++]=it;
            }
        }
        return res;
    }
};