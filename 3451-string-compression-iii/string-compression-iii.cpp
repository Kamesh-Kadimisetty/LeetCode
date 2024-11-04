class Solution {
public:
    string compressedString(string word) {
        string result;
        if(word.size()==1){
            result+=to_string(1);
            result+=word[0];;
            return result;
        }
        int count=1;
        for(int i=1;i<word.size();i++){
            if(word[i]!=word[i-1]||count==9){
                result+=to_string(count);
                result+=word[i-1];
                count=1;
            }
            else{
                count++;
            }
            if(word.size()-1==i){
                result+=to_string(count);
                result+=word[i];
            }
        }
        return result;
    }
};