class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long len=1,shift=0;
        vector<long long>lenghts;
        for(auto it:operations){
            len*=2;
            lenghts.push_back(len);
            if(len>=k) break;
        }
        for(int i=lenghts.size()-1;i>=0;i--){
            long long half=lenghts[i]/2;
            if(k>half){
                k-=half;
                if(operations[i]==1) shift++;
            }
        }
        return (('a'+shift-'a')%26)+'a';
    }
};