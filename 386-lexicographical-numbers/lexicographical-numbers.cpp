class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> ans;
        vector<int> res;
        for(int i=1;i<=n;i++){
            ans.push_back(to_string(i));
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<n;i++){
            res.push_back(stoi(ans[i]));
        }
        return res;
    }
};