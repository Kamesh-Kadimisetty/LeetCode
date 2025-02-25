class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int val=0.05*n;
        double sum=0;
        for(int i=val;i<n-val;i++){
            sum+=arr[i];
        }
        return (sum)/double(n-(2*val));
    }
};