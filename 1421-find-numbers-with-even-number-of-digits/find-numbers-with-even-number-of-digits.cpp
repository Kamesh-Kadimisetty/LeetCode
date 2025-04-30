class Solution {
public:
    int countdigits(int n){
        int count=0;
        while(n){
            count++;
            n/=10;
        }
        return count;
    }
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(countdigits(nums[i])%2==0){
                cnt++;
            }
        }
        return cnt;
    }
};