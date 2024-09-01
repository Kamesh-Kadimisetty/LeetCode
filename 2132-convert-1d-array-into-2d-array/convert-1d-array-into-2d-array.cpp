class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        int size=original.size();
        if(n*m!=size){
            return ans;
        }
        int k=0;
        for(int i=0;i<m;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(original[k]);
                k++;
            }
                ans.push_back(temp);
        }
        return ans;
    }
};