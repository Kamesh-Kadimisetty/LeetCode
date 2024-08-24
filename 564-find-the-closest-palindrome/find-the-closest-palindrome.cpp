class Solution {
public:
    string nearestPalindromic(string n) {
        int len=n.length();
        long long num=stoll(n);
        vector<long long> candidates;
        candidates.push_back((long long)pow(10,len-1)-1);
        candidates.push_back((long long)pow(10,len)+1);
        long long prefix=stoll(n.substr(0,(len+1)/2));
        vector<long long>allprefixes={prefix-1,prefix,prefix+1};

        for(auto i:allprefixes){
            string prefixstr=to_string(i);
            string palindrome;
            if((len%2)==0){
                palindrome=prefixstr+string(prefixstr.rbegin(),prefixstr.rend());
            }
            else{
                palindrome=prefixstr+string(prefixstr.rbegin()+1,prefixstr.rend());
            }
            candidates.push_back(stoll(palindrome));
        }
        long long closest=-1;
        for(auto ans:candidates){
            if(ans==num) continue;
            if(closest==-1 || abs(closest-num)>abs(ans-num)|| abs(closest-num)==abs(ans-num)&& closest>num){
                closest=ans;
            }
        }
        return to_string(closest);
    }
};