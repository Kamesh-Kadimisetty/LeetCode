class Solution {
public:
    string answerString(string word, int frnds) {
        if(frnds==1) return word;
        int n=word.size();
        int len=n-frnds+1;
        vector<string>splits;
        for(int i=0;i<=n-len;i++){
            splits.push_back(word.substr(i,len));
        }
        for(int i=n-len;i<n;i++){
            splits.push_back(word.substr(i));           
        }
        sort(splits.rbegin(),splits.rend());
        return splits[0];
    }
};