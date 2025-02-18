class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>qu;
        qu.push({beginWord,1});
        st.erase(beginWord);
        while(!qu.empty()){
            string word=qu.front().first;
            int steps=qu.front().second;
            qu.pop();
            if(endWord==word) return steps;
            for(int i=0;i<word.size();i++){
                char orginal=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        qu.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i]=orginal;
            }
        }
        return 0;
    }
};