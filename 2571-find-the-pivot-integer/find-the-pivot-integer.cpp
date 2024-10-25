class Solution {
public:
    int pivotInteger(int n) {
        int arr[n];
        int arr1[n];
        arr[0]=1;
        arr1[n-1]=n;
        for(int i=1;i<n;i++){
            arr[i]=arr[i-1]+i+1;
        }
        for(int i=n-2;i>=0;i--){
            arr1[i]=arr1[i+1]+i+1;
        }
        for(int i=0;i<n;i++){
            if(arr[i]==arr1[i]){
                return i+1;
            }
        }
        return -1;
    }
};