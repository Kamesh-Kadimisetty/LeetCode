class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size(),j=0;
        vector<int>result;
        sort(nums.begin(),nums.end());
        set<int>st;
        for(auto it:nums) st.insert(it);
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end()){
                result.push_back(i);
            }
        }
        return result;
    }
};