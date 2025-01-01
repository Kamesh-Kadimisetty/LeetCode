class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>hash(26,0);
        for(char it:s){
            hash[it-'a']++;
        }
        int i=0;
        for(char it:s){
            if(hash[it-'a']==1){
                return i;
            }
            i++;
        }
        return -1;
    }
};