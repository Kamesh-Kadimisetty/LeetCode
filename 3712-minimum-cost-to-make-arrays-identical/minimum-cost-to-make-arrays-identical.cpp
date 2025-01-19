class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n=arr.size();
        long long result1=0;
        for(int i=0;i<n;i++){
            result1+=abs(arr[i]-brr[i]);
        }
        long long result2=k;
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        for(int i=0;i<n;i++){
            result2+=abs(arr[i]-brr[i]);
        }
        return min(result1,result2);
    }
};