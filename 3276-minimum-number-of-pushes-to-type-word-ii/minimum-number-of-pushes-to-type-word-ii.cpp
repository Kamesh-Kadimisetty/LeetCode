class Solution {
public:
    int minimumPushes(string word) {
        int minpushes=0,key=0;
        int hash[26]={0};
        for(int i=0;i<word.size();i++){
            hash[word[i]-'a']++;
        }
        sort(hash,hash+26);
        reverse(hash,hash+26);
        for(int i=0;i<26;i++){
             cout<<hash[i]<<" ";
        }
        for(int i=0;i<26;i++){
            if(i<8){
            key=1;
            minpushes+=(hash[i]*key);
            }
            else if(i>=8 && i<16){
            key=2;
            minpushes+=(hash[i]*key);
            }
            else if(i>=16 && i<24){
            key=3;
            minpushes+=(hash[i]*key);
            }
            else{
            key=4;
            minpushes+=(hash[i]*key); 
            }
        }
        return minpushes;
    }
};