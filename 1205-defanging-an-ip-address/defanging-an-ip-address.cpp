class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for(char ad : address){
            if(ad=='.'){
                ans+="[.]";
            }
            else{
                ans+=ad;
            }
        }
        return ans;
    }
};