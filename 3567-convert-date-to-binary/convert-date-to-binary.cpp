class Solution {
public:
    string tobinary(int n){
        string result="";
        while(n>0){
            result=to_string(n%2)+result;
            n=n/2;
        }
        return result;
    }
    string convertDateToBinary(string date) {
        string ans="";
        ans.append(tobinary(stoi(date.substr(0,4))));
        ans+='-';
        ans.append(tobinary(stoi(date.substr(5,2))));
        ans+='-';
        ans.append(tobinary(stoi(date.substr(8,2))));
        return ans;
    }
};