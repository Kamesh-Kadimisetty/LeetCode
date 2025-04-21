class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        int n=diff.size();
        vector<long long>prefixsum(n+1,0);
        for(int i=1;i<=n;i++){
            prefixsum[i]=prefixsum[i-1]+diff[i-1];
        }
        long long maxi=*max_element(prefixsum.begin(),prefixsum.end());
        long long mini=*min_element(prefixsum.begin(),prefixsum.end());
        long long low=lower-mini,high=upper-maxi;
        return high>=low?high-low+1:0;
    }
};
