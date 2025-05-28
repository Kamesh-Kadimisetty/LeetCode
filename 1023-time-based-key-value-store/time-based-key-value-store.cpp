class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mpp;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto &arr=mpp[key];
        int low=0,high=arr.size()-1;
        string result="";
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid].first<=timestamp){
                result=arr[mid].second;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */