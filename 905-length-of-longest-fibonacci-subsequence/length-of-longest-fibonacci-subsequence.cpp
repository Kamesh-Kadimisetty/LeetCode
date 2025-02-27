class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int>mpp;
        int maxlen=0,n=arr.size();
        for(auto it:arr){
            mpp[it]++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int len=2;
                int prev=arr[i];
                int curr=arr[j];
                while(prev<curr){
                    if(mpp.find(prev+curr)!=mpp.end()){
                        int temp=prev;
                        prev=curr;
                        curr=temp+curr;
                        len++;
                    }
                    else{
                        maxlen=max(maxlen,len);
                        break;
                    }
                }
            }
        }
        return maxlen>2?maxlen:0;
    }
};