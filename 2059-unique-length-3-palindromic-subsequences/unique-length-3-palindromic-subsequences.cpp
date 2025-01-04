class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int total=0,n=s.size();
        set<char>letters;
        for(auto it:s){
            letters.insert(it);
        }
        for(char l:letters){
            int i=-1;
            int j=0;
            for(int k=0;k<n;k++){
                if(s[k]==l){
                    if(i==-1){
                        i=k;
                    }
                    j=k;
                }
            }
            set<char>st;
            for(int p=i+1;p<j;p++){
                st.insert(s[p]);
            }
            total+=st.size();
        }
        return total;
    }
};