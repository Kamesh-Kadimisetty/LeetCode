class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int>res,prev,curr;
        for(auto it:arr){
            curr={it};
            for(auto j:prev){
                curr.insert(j|it);
            }
            prev=curr;
            for(auto j:prev){
                res.insert(j);
            }
        }
        return res.size();
    }
};