class Solution {
public:
    // vector<string>ans;
    // void func(int ind,vector<string>& words,vector<int>& groups,vector<string>& result){
    //     if(ind>=words.size()){
    //         if(res.size()>ans.size()){
    //             ans=res;
    //         }
    //         return ;
    //     }

    // }
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>result;
        // func(0,words,groups,result);
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