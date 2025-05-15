class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>result;
        int n=words.size(),rem=groups[0];
        result.push_back(words[0]);
        for(int i=1;i<n;i++){
            if(groups[i]!=rem){
                result.push_back(words[i]);
                rem=groups[i];
            }
        }
        return result;
    }
};