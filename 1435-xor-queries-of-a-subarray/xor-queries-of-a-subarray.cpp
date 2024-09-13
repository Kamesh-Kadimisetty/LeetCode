class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> answers;
        for(int i=0;i<queries.size();i++){
            int res=0;
            for(int j=queries[i][0];j<=queries[i][1];j++){
                res^=arr[j];
            }
            answers.push_back(res);
        }
        return answers;
    }
};