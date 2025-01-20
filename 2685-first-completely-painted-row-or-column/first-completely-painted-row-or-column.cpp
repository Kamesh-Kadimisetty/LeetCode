class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        unordered_map<int,pair<int,int>>mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mpp[mat[i][j]]={i,j};
            }
        }
        vector<int>rows(n,0);
        vector<int>cols(m,0);
        for(int i=0;i<arr.size();i++){
            auto [r,c]=mpp[arr[i]];
            rows[r]++;
            cols[c]++;
            if(rows[r]==m || cols[c]==n){
                return i;
            }
        }
        return -1;
    }
};