class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size(),first=INT_MAX,second=INT_MAX;
        for(auto third:nums){
            if(third<=first) first=third;
            else if(third<=second) second=third;
            else return true;
        }
        return false;
    }
};