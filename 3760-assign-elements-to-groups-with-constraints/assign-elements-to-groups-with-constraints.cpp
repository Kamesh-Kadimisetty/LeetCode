class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n=groups.size();
        int m=elements.size();
        vector<int>result(n,-1);
        unordered_map<int,int>mpp;
        for(int i=0;i<m;i++){
            if(mpp.find(elements[i])==mpp.end()){
                mpp[elements[i]]=i;
            }
        }
        for(int i=0;i<n;i++){
            int bestindex=INT_MAX;
            int num=groups[i];
            for(int j=1;j*j<=num;j++){
                if(num%j==0 && mpp.count(j)){
                    bestindex=min(bestindex,mpp[j]);
                }
                //if groups[i]%j==0 then groups[i]/j is also divisor
                if(j!=num/j && num%j==0 && mpp.count(num/j)){
                    bestindex=min(bestindex,mpp[num/j]);
                }
            }
            result[i]=bestindex==INT_MAX?-1:bestindex;
        }
        return result;
    }
};