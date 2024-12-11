class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string>result;
        for(int i=0;i<words.size();i++){
            int start=0,j;
            for(j=0;j<words[i].size();j++){
                if(words[i][j]==separator){
                    string s=words[i].substr(start,j-start);
                    if(s!="")result.push_back(s);
                    start=j+1;
                }
            }
            string u=words[i].substr(start,j-start);
            if(u!="")result.push_back(u);
        }
        return result;
    }
};