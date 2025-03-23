class Solution {
public:
    vector<string>func(string s,vector<string>& products){
        vector<string>ans;
        int n=s.size();
        int low=0,high=products.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            string req=products[mid].substr(0,n);
            if(req<s){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        for(int i=low;i<low+3 && i<products.size();i++){
            if(products[i].substr(0,n)==s){
                ans.push_back(products[i]);
            }
        }
        return ans;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>>result;
        for(int i=0;i<searchWord.size();i++){
            result.push_back(func(searchWord.substr(0,i+1),products));
        }
        return result;
    }
};