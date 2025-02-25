class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int MOD=1e9+7,result=0;
        int curr=0,even=1,odd=0;
        for(int i=0;i<n;i++){
            curr+=arr[i];
            if(curr%2==0){
                even++;
                result=(result+odd)%MOD;
            }
            else{
                odd++;
                result=(result+even)%MOD;;
            }
        }
        return result;
    }
};