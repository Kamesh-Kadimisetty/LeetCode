class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        int oddnums=0;
        if(n<k){
            return false;
        }
        else if(n==k){
            return true;
        }
        else{
            vector<int>hash(26,0);
            for(auto c:s){
                hash[c-'a']++;
            }
            for(auto it:hash){
                cout<<it<<endl;
                if(it%2==1){
                    oddnums++;
                }
            }
        }
        return oddnums<=k?true:false;
    }
};