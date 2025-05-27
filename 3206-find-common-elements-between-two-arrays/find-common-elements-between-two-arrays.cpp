class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int x=0,y=0;
        unordered_set<int>st1(nums1.begin(),nums1.end());
        unordered_set<int>st2(nums2.begin(),nums2.end());
        for(auto it:nums1){
            if(st2.find(it)!=st2.end()) x++;
        }
        for(auto it:nums2){
            if(st1.find(it)!=st1.end()) y++;
        }
        return {x,y};
    }
};