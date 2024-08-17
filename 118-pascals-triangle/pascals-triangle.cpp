class Solution {
public:
    int ncr(int n,int r){
        int res=1;
        for(int i=0;i<r;i++){
            res=res*(n-i);
            res=res/(i+1);
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
          vector<int>row;
            for(int j=0;j<i;j++){
                row.push_back(ncr(i-1,j));
            }
            ans.push_back(row);
        }
        return ans ;
    }
};