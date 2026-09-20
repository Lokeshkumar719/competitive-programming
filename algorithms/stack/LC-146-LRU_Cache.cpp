class LRUCache {
public:
    int cap;
    list<pair<int, int>> ls;
    map<int, list<pair<int, int>>::iterator> mp;
    LRUCache(int capacity) { cap = capacity; }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;
        auto it = mp[key];
        int val = it->second;
        ls.erase(it);
        ls.push_front({key, val});
        mp[key] = ls.begin();
        return val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            auto it = mp[key];
            ls.erase(it);
        } else {
            if (cap == ls.size()) {
                auto it = ls.back();
                mp.erase(it.first);
                ls.pop_back();
            }
        }
        ls.push_front({key, value});
        mp[key] = ls.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */