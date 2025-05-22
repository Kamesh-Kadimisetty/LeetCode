class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mr=m,mc=n;
        for(auto it:ops){
            if(it[0]<mr) mr=it[0];
            if(it[1]<mc) mc=it[1];
        }
        return mr*mc;
    }
};