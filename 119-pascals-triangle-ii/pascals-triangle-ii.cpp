class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        long long ans=1;
        for(int i=1;i<=rowIndex;i++){
            ans=ans*(rowIndex+1-i);
            ans=ans/i;
            res.push_back(ans);
        }
        return res;
    }
};