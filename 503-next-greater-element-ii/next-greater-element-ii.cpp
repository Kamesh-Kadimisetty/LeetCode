class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>nge;
        int n=nums.size();
        if(n==1){
            nge.push_back(-1);
            return nge;
        }
        for(int i=0;i<n;i++){
            int j=(i+1)%n;
            while(j!=i){
                if(nums[i]<nums[j]){
                    nge.push_back(nums[j]);
                    break;
                }
                else{
                    j=(j+1)%n;
                    if(i==j){
                        nge.push_back(-1);
                        break;
                    }
                }
            }
        }
        return nge;
    }
};