class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int prefixsum=0,sortsum=0;
        int chunks=0;
        for(int i=0;i<arr.size();i++){
            prefixsum+=arr[i];
            sortsum+=i;
            if(prefixsum==sortsum){
                chunks++;
            }
        }
        return chunks;
    }
};