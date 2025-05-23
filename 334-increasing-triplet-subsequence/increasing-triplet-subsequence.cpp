class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size(),first=INT_MAX,second=INT_MAX;
        for(auto third:nums){
            if(second<third){
                return true;
            }
            else if(third<=first) first=third;
            else second=third;
        }
        return false;
    }
};