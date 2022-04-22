class UndergroundSystem {
public:
    
    unordered_map<int, pair<string,int> > mp;
    unordered_map< string , pair<int,int> > mst;
    UndergroundSystem() {
        ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);  
        mp.clear();
        mst.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int total;
        int count;
        if(mst.find(mp[id].first+stationName )!=mst.end())
        {
            total = mst[mp[id].first+stationName].first ;
            count = mst[mp[id].first+stationName].second ;
        }
        else
        {
            total = 0;
            count = 0;
        }
        total += t-mp[id].second;
        count += 1;
        
         
        mst [ mp[id].first+stationName ] = { total,count };
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)mst[ startStation+endStation ].first/(double)mst[ startStation+endStation ].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */