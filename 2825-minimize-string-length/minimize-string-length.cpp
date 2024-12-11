class Solution {
public:
    int minimizedStringLength(string s) {
        vector<int>hash(26,0);
        int count=0; 
        for(auto i:s){
            hash[i-'a']++;
        }
        for(auto j:hash){
            if(j!=0){
                count++;
            }
        }
        return count;
    }
};