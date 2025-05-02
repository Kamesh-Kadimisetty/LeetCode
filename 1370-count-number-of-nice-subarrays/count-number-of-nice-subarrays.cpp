class Solution {
public:
    int func(vector<int>& nums, int k){
        int n=nums.size(),i=0,j=0,cnt=0,result=0;
        while(j<n){
            if(nums[j]%2==1) cnt++;
            while(cnt>k){
                if(nums[i]%2==1) cnt--;
                i++;
            }
            result+=j-i+1;
            j++;
        }
        return result;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
};