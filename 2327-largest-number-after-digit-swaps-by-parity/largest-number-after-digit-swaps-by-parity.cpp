class Solution {
public:
    int largestInteger(int num) {
        string s=to_string(num);
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                if(s[j]>s[i] && s[i]%2==s[j]%2){
                    swap(s[i],s[j]);
                    num=max(num,stoi(s));
                }
            }
        }
        return num;
    }
};