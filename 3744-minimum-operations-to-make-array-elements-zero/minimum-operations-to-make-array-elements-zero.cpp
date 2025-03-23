class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long result=0;
        for(auto it:queries){
            long long l=it[0],h=it[1],cnt=0;
            for(long long d=1,prev=1;d<17;d++){
                long long curr=prev*4LL;
                long long r=max(l,prev),k=min(h,curr-1);
                if(r<=k)cnt+=(k-r+1)*d;
                prev=curr;
            }
            result+=((cnt+1)/2);
        }
        return result;
    }
};