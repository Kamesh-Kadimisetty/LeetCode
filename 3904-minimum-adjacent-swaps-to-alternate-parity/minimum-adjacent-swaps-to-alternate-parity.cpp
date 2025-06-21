class Solution {
public:
    int func(vector<int>&arr){
        int ops=0;
        for(int i=0;i<arr.size();i++){
            ops+=abs(arr[i]-2*i);
        }
        return ops;
    }
    int minSwaps(vector<int>& nums) {
        vector<int>odd,even;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) even.push_back(i);
            else odd.push_back(i);
        }
        int n=nums.size(),e=even.size(),o=odd.size();
        if(abs(o-e)>1) return -1;
        int minops=INT_MAX;
        if(n%2==0){
            minops=min(func(odd),func(even));
        }
        else{
            if(o>e) minops=func(odd);
            else minops=func(even);
        }
        return minops;
    }
};