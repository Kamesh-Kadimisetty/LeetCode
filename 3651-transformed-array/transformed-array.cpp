class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size(),j;
        vector<int>result(n);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                int k=nums[i];
                j=i;
                while(k--){
                    j=(j+1)%n;
                }
                result[i]=nums[j];
            }
            else if(nums[i]<0){
                int k=abs(nums[i]);
                j=i;
                while(k--){
                    j=(j+n-1)%n;
                }
                result[i]=nums[j];
            }
            else{
                result[i]=0;
            }
        }
        return result;
    }
};