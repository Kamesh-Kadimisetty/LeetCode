class Solution {
public:
    void func(string curr,int n,vector<string>&allstrings){
        if(curr.size()==n){
            allstrings.push_back(curr);
            return;
        }
        for(char ch='a';ch<='c';ch++){
            if(curr.size()>0 && curr.back()==ch){
                continue;
            }
            func(curr+ch,n,allstrings);
        }
    }
    string getHappyString(int n, int k) {
        vector<string>allstrings;
        func("",n,allstrings);
        sort(allstrings.begin(),allstrings.end());
        return allstrings.size()<k?"":allstrings[k-1];
    }
};