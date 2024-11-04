class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1||chars.size()==0){
            return chars.size();
        }
        int count=1;
        int j=0;
        for(int i=1;i<chars.size();i++){
            if(chars[i]!=chars[i-1]){
                if(count==1){
                    chars[j++]=chars[i-1];
                }
                else{
                    chars[j++]=chars[i-1];
                    string ct=to_string(count);
                    for(auto k:ct){
                        chars[j++]=k;
                    }
                }
                count=1;
            }
            else{
                count++;
            }
            if(i==chars.size()-1){
                if(count==1){
                    chars[j++]=chars[i];
                }
                 else{
                    chars[j++]=chars[i];
                    string ct=to_string(count);
                    for(auto k:ct){
                        chars[j++]=k;
                    }
                }
            }
        }
        // chars.resize(j);
        return j;
    }
};