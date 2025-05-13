class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int MOD=1e9+7;
        vector<long long>arr(26,0);
        for(auto it:s){
            arr[it-'a']++;
        }
        for(int i=0;i<t;i++){
            long long x=arr[25];
            for(int k=25;k>0;k--){
                arr[k]=arr[k-1];
            }
            arr[0]=x%MOD;
            arr[1]=(arr[1]+x)%MOD;
        }
        long long total=accumulate(arr.begin(),arr.end(),0LL);
        return total%MOD;
    }
};