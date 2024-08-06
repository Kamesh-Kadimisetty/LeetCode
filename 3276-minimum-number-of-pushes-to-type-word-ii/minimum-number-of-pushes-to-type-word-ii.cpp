class Solution {
public:
    int minimumPushes(string word) {
        int minpushes=0;
        int hash[26]={0};
        for(int i=0;i<word.size();i++){
            hash[word[i]-'a']++;
        }
        sort(hash,hash+26);
        reverse(hash,hash+26);
        for(int i=0;i<26;i++){
            if(i<8)
            minpushes+=(hash[i]*1);
            else if(i>=8 && i<16)
            minpushes+=(hash[i]*2);
            else if(i>=16 && i<24)
            minpushes+=(hash[i]*3);
            else
            minpushes+=(hash[i]*4); 
        }
        return minpushes;
    }
};