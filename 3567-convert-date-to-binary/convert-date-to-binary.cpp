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
        string year=date.substr(0,4);
        string month=date.substr(5,2);
        string dat=date.substr(8,2);
        ans.append(tobinary(stoi(year)));
        ans+='-';
        ans.append(tobinary(stoi(month)));
        ans+='-';
        ans.append(tobinary(stoi(dat)));
        return ans;
    }
};