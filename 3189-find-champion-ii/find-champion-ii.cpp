class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>in_degree(n,0);
        for(auto edge:edges){
           in_degree[edge[1]]++;
        }
        int ans=-1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(in_degree[i]==0){
                ans=i;
                cnt++;
            }
        }
        return cnt>1?-1:ans;
    }
};