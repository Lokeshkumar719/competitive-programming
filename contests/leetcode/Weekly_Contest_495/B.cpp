class EventManager {
private:
    map<int,int>mp;
    priority_queue<pair<int,int>>pq;
public:
    EventManager(vector<vector<int>>& events) {
        for(auto &it:events){
            mp[it[0]]=it[1];
            pq.push({it[1],-it[0]});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId]=newPriority;
        pq.push({newPriority,-eventId});
    }
    
    int pollHighest() {
        while(!pq.empty()){
            int priority=pq.top().first;
            int id=-pq.top().second;
            if(mp.count(id) && mp[id]==priority){
                pq.pop();
                mp.erase(id);
                return id;
            }
            pq.pop();
        }
        return -1;
    }
};
