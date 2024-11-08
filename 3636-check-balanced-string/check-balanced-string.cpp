class Solution {
public:
    bool isBalanced(string num) {
        int n=num.size();
        int even=0,odd=0;
        for(int i=0;i<n-1;i+=2){
            even+=(num[i]-'0');
            odd+=(num[i+1]-'0');
        }
        if(n%2==1)even+=(num[n-1]-'0');
        return even==odd;
    }
};