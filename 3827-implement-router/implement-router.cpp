class Router {
public:
    queue<vector<int>>qu;
    map<vector<int>,int>mpp; //for duplicates
    unordered_map<int,vector<int>>times; //stores timestamps
    unordered_map<int,int>st; //count removed packets
    int maxsize=0;
    Router(int memoryLimit) {
        maxsize=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int>packet={source,destination,timestamp};
        if(mpp.count(packet)) return false;
        if(qu.size()==maxsize){
            vector<int> old=qu.front();
            st[old[1]]++;
            mpp.erase(old);
            qu.pop();
        }
        qu.push(packet);
        mpp[packet]++;
        times[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(qu.empty())return {};
        vector<int>packet=qu.front();
        qu.pop();
        st[packet[1]]++;
        mpp.erase(packet);
        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(times.find(destination)==times.end()) return 0;
        auto &p=times[destination];
        int temp=st[destination];
        auto low=lower_bound(p.begin()+temp,p.end(),startTime);
        auto high=upper_bound(p.begin()+temp,p.end(),endTime);
        return int(high-low);
    }
};