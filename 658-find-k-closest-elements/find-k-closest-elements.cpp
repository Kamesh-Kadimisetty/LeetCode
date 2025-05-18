class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int i=0,j=n-1;
        while(j-i>=k){
            if(abs(arr[i]-x)>abs(arr[j]-x)){
                i++;
            }
            else{
                j--;
            }
        }
        vector<int>result(arr.begin()+i,arr.begin()+i+k);
        return result;
    }
};