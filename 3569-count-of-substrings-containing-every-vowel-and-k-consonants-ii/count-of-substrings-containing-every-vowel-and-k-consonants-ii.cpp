class Solution {
public:
    bool isvowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    long long atleastk(string word,int k){
        long long total=0;
        int start=0,end=0,n=word.size();
        unordered_map<char,int>mpp;
        int ccnt=0;
        while(end<n){
            char ch=word[end];
            if(isvowel(ch)){
                mpp[ch]++;
            }
            else{
                ccnt++;
            }
            while(mpp.size()==5 && ccnt>=k){
                total+=n-end;
                char ch1=word[start];
                if(isvowel(ch1)){
                    if(--mpp[ch1]==0){
                        mpp.erase(ch1);
                    }
                }
                else{
                    ccnt--;
                }
                start++;
            }
            end++;
        }
        return total;
    }
    long long countOfSubstrings(string word, int k) {
        return atleastk(word,k)-atleastk(word,k+1);
    }
};