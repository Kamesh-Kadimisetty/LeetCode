class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int>st;
        int n=digits.size();
        for(int i=0;i<n;i++){
            if(digits[i]%2==1) continue;
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i!=j && j!=k && i!=k && digits[j]!=0) st.insert(digits[j]*100+digits[k]*10+digits[i]);
                }
            }
        }
        vector<int>result(st.begin(),st.end());
        return result;
    }
};