class LFUCache {
public:
    using lpii = list<pair<int, int>>;
    map<int, pair<int, lpii::iterator>> key_to_iterator;
    int cap;
    map<int, lpii> freq_to_list;
    LFUCache(int capacity) { cap = capacity; }

    int get(int key) {
        if (key_to_iterator.find(key) == key_to_iterator.end())
            return -1;

        auto& [freq, it] = key_to_iterator[key];
        int val = it->second;
        int newFreq = freq + 1;
        freq_to_list[freq].erase(it);
        if (freq_to_list[freq].empty())
            freq_to_list.erase(freq);
        freq_to_list[newFreq].push_front({key, val});
        key_to_iterator[key] = {newFreq, freq_to_list[newFreq].begin()};
        return val;
    }

    void put(int key, int value) {
        if (key_to_iterator.find(key) != key_to_iterator.end()) {
            auto& [freq, it] = key_to_iterator[key];
            int val = it->second;
            int newFreq = freq + 1;
            freq_to_list[freq].erase(it);
            if (freq_to_list[freq].empty())
                freq_to_list.erase(freq);
            freq_to_list[newFreq].push_front({key, value});
            key_to_iterator[key] = {newFreq, freq_to_list[newFreq].begin()};
        } else {
            if (cap == key_to_iterator.size()) {
                auto& [freq, it] = *freq_to_list.begin();
                int newFreq = 1;
                int key_to_remove = it.back().first;
                key_to_iterator.erase(key_to_remove);
                it.pop_back();
            }
            freq_to_list[1].push_front({key, value});
            key_to_iterator[key] = {1, freq_to_list[1].begin()};
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */