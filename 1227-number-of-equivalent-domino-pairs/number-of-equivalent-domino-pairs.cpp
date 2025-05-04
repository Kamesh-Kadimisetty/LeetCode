class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int>mpp;
        for(auto it:dominoes){
            int a=it[0];
            int b=it[1];
            if(a<b) mpp[{a,b}]++;
            else mpp[{b,a}]++;
        }
        int cnt=0;
        for(auto it:mpp){
            if(it.second>1){
                cnt+=(it.second*(it.second-1))/2;
            }
        }
        return cnt;
    }
};