class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>mymap;
        for (int i = 0; i < arr.size(); i++) {
             mymap[arr[i]]++;
        }
        int p=0;
        for (auto &str : arr) {
        if(mymap[str]==1){
            p++;
            if(p==k){
                return str;
            }
        }
        }
        return "";
    }
};