class Solution {
public:
    void func(int ind,int currxor,vector<int> &nums,int &total){
        int n=nums.size();
        if(ind==n){
            total+=currxor;
            return;
        }
        func(ind+1,currxor^nums[ind],nums,total);
        func(ind+1,currxor,nums,total);
    }
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        int total=0;
        func(0,0,nums,total);
        return total;
    }
};