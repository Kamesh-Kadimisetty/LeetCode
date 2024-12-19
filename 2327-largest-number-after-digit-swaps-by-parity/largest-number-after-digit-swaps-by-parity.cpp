class Solution {
public:
    int largestInteger(int num) {
        vector<int>odd;
        vector<int>even;
        string s=to_string(num);
        for(auto it:s){
            if(it%2==0){
                even.push_back(it);
            }
            else{
                odd.push_back(it);
            }
        }
        sort(even.rbegin(),even.rend());
        sort(odd.rbegin(),odd.rend());
        int k=0,j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]%2==0){
                s[i]=even[j];
                j++;
            }
            else{
                s[i]=odd[k];
                k++;
            }
        }
        return stoi(s);
    }
};