class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        for(int i=1;i<n-1;i++){
            int j=i,k=i;
            if(nums[i]==nums[i-1]) continue;
            while(j>0 && nums[j]==nums[i]){
                j--;
            }
            while(k<n-1 && nums[k]==nums[i]){
                k++;
            }
            if((nums[i]>nums[j] && nums[i]>nums[k]) || (nums[i]<nums[j] && nums[i]<nums[k])){
                cnt++;
            } 
        }
        return cnt;
    }
};