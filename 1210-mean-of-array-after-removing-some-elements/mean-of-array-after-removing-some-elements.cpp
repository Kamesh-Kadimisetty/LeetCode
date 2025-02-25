class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int val=0.05*n;
        double sum=accumulate(arr.begin(),arr.end(),0.0);
        double remove=0;
        cout<<val<<endl;
        for(int i=0;i<val;i++){
            remove+=arr[i];
            remove+=arr[n-i-1];
        }
        cout<<sum<<" "<<remove;
        return (sum-remove)/double(n-(2*val));
    }
};