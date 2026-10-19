class RandomizedSet {
public:
    vector<int> elements;
    unordered_map<int,int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val))
            return false;

        elements.push_back(val);
        mp[val] = elements.size() - 1;

        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val))
            return false;
        int idx = mp[val];
        int lastElement = elements.back();
        elements[idx] = lastElement;
        mp[lastElement] = idx;
        // removing should be done at the end only
        mp.erase(val);
        elements.pop_back();
        return true;
    }
   
    int getRandom() {
        int idx = rand() % (elements.size());
        return elements[idx]; 
    }
};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */