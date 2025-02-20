class Solution {
public:
    // void func(string curr,set<string>&st,int len){
    //     if(curr.size()==len){
    //         st.insert(curr);
    //         return;
    //     }
    //     func(curr+'1',st,len);
    //     func(curr+'0',st,len);
    // }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        string result="";
        for(int i=0;i<n;i++){
            char ch=nums[i][i];
            if(ch=='0'){
                result+='1';
            }
            else{
                result+='0';
            }
        }
        return result;
    }
};