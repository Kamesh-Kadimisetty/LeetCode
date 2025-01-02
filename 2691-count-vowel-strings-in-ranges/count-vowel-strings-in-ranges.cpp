class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        int m=queries.size();
        vector<int>ans;
        vector<int>vowels(n);
        int i=0;
        for(auto it:words){
            int s=it.size();
            if((it[0]=='a' || it[0]=='e' || it[0]=='i' || it[0]=='o' || it[0]=='u')&& 
                (it[s-1]=='a' || it[s-1]=='e' || it[s-1]=='i' || it[s-1]=='o' || it[s-1]=='u')){
                    vowels[i]=1;
            }
            else{
                vowels[i]=0;
            }
            i++;
        }
        vector<int>prefixsum(n);
        prefixsum[0]=vowels[0];
        cout<<prefixsum[0]<<endl;
        for(int i=1;i<n;i++){
            prefixsum[i]=prefixsum[i-1]+vowels[i];
            cout<<prefixsum[i]<<endl;
        }
        for(auto it:queries){
            int left=it[0];
            int right=it[1];
            if(left>0){
                ans.push_back(prefixsum[right]-prefixsum[left-1]);
            }
            else{
                ans.push_back(prefixsum[right]);
            }
        }
        return ans;
    }
};