class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
        map<string,int>count;
        for(int i=0;i<n;i++){
            string currstr;
            for(int j=i;j<n;j++){
                if(currstr.empty() || currstr.back()==s[j]){
                    currstr.push_back(s[j]);
                    count[currstr]++;
                }
                else{
                    break;
                }
            }
        }
        int maxlen=0;
        for(auto c:count){
            string str=c.first;
            if(c.second>=3 && str.size()>maxlen){
                maxlen=str.size();
            }
        }
        return maxlen==0?-1:maxlen; 
    }
 };