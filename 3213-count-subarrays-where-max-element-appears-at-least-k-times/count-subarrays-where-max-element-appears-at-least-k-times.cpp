class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxele=*max_element(nums.begin(),nums.end());
        int cnt=0,i=0,j=0,n=nums.size();
        long long result=0;
        while(j<n){
            if(nums[j]==maxele) cnt++;
            while(cnt>=k){
                result+=n-j;
                if(nums[i]==maxele) cnt--;
                i++;
            }
            j++;
        }
        return result;
    }
};