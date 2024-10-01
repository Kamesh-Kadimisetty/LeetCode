class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>freq(k,0);
        for(int i=0;i<arr.size();i++){
            int rem=((arr[i]%k)+k)%k;
            freq[rem]++;
        }
        if(freq[0]%2!=0){
            return false;
        }
        for(int i=1;i<=k/2;i++){
            if(freq[i]!=freq[k-i]){
                return false;
            }
        }
        return true;
    }
};