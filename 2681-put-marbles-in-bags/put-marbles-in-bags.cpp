class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        if(n==k)return 0;
        vector<int>diff(n-1);
        for(int i=0;i<n-1;i++){
            diff[i]=weights[i]+weights[i+1];
        }
        sort(diff.begin(),diff.end());
        long long result=0;
        for(int i=0;i<k-1;i++){
            result+=diff[n-i-2]-diff[i];
        }
        return result;
    }
};