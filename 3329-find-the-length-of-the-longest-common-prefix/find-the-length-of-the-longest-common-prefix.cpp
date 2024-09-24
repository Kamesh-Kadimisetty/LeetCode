class Solution {
public:
    int length(int n){
        string ans=to_string(n); 
        return ans.size();
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> unst;
        for(auto it:arr1){
            while(it>0){
                unst.insert(it);
                it/=10;
            }
        }
          int maxi=0;
        for(auto it:arr2){
            while(it>0){
                if(unst.find(it)!=unst.end()){
                      maxi=max(maxi,length(it));
                        break;
                }
                it/=10;
            }
        }
        return maxi;
    }
};