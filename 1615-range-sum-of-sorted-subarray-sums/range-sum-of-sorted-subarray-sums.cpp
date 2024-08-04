class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // int N=n*(n+1)/2;
        int arr[n*(n+1)/2],k=0;
        for(int i=0;i<n;i++){
                int s=0;
            for(int j=i;j<n;j++){
                s+=nums[j];
                arr[k++]=s;
            }
        }
        sort(arr,arr+n*(n+1)/2);
        int sum=0;
        const int mod=1e9+7;
        for(int i=left-1;i<right;i++){
            sum=(sum+arr[i])%mod;
        }
        return sum;
    }
};