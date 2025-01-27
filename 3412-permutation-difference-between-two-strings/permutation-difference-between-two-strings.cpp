class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int>hash1(26,0);
        vector<int>hash2(26,0);
        for(int i=0;i<s.size();i++){
            hash1[s[i]-'a']=i;
            hash2[t[i]-'a']=i;
        }
        int result=0;
        for(int i=0;i<26;i++){
            result+=abs(hash1[i]-hash2[i]);
        }
        return result;
    }
};