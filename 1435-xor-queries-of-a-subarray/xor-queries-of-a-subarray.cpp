class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>result;
        vector<int>prefixor(n+1,0);
        for(int i=0;i<n;i++){
            prefixor[i + 1] = prefixor[i] ^ arr[i];
        }
        for(auto q: queries){
            result.push_back(prefixor[q[0]]^prefixor[q[1]+1]);
        }
        return result;
    }
};