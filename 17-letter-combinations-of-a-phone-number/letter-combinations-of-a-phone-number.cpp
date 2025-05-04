class Solution {
public:
    void func(int ind,string ans,string digits, vector<string>&result, unordered_map<int,vector<char>> &mpp){
        int n=digits.size();
        if(ind>n-1){
            if(ans!="")result.push_back(ans);
            return;
        }
        vector<char>arr=mpp[digits[ind]-'0'];
        int x=arr.size();
        for(int i=0;i<x;i++){
            func(ind+1,ans+arr[i],digits,result,mpp);
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string>result;
        unordered_map<int,vector<char>>mpp;
        int num=2,cnt=0;
        for(char ch='a';ch<='o';ch++){
            mpp[num].push_back(ch);
            cnt++;
            if(cnt==3){
                cnt=0;
                num++;
            }
        }
        for(char ch='p';ch<='s';ch++){
            mpp[7].push_back(ch);
        }
        for(char ch='t';ch<='v';ch++){
            mpp[8].push_back(ch);
        }
        for(char ch='w';ch<='z';ch++){
            mpp[9].push_back(ch);
        }
        func(0,"",digits,result,mpp);
        return result;
    }
};