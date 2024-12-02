class Solution {
public:
    bool checkprefix(string word, string search){
        int i=0;
        int n=word.size(),m=search.size();
        if(n<m) return false;
        while(i<m){
            if(word[i]==search[i]){
                i++;
            }
            else{
                return false;
            }
        }
        return true;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        int count=0;
        vector<string>words;
        int start=0;
        for(int i=0;i<sentence.size();i++){
            count++;
            if(sentence[i]==' '){
                words.push_back(sentence.substr(start,count));
                start=i+1;
                count=0;
            }
        }
        words.push_back(sentence.substr(start,count));
        for(int i=0;i<words.size();i++){
            if(checkprefix(words[i],searchWord)){
                return i+1;
            }
        }
        return -1;
    }
};