class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size(),a,b;
        vector<int>hash(n*n+1,0);
        set<int>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(st.find(grid[i][j])!=st.end()){
                    a=grid[i][j];
                }
                st.insert(grid[i][j]);
                hash[grid[i][j]]=1;
            }
        }
        for(int i=1;i<=n*n;i++){
            if(hash[i]==0){
                b=i;
                break;
            }
        }
        return {a,b};
    }
};