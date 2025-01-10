class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int maxcount[26]={0};
        for(auto it:words2){
            int count[26]={0};
            for(auto c:it){
                count[c-'a']++;
            }
            for(int i=0;i<26;i++){
                maxcount[i]=max(maxcount[i],count[i]);
            }
        }
        vector<string>result;
        for(auto it:words1){
            int count[26]={0};
            for(auto c:it){
                count[c-'a']++;
            }
            bool universal=true;
            for(int i=0;i<26;i++){
               if(count[i]<maxcount[i]){
                    universal=false;
                    break;
               }
            }
            if(universal){
                result.push_back(it);
            }
        }
        return result;
    }
};