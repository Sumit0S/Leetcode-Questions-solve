class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        // Check if the key exists in the cache
        if (mpp.find(key) == mpp.end()) {
            return -1; // Return -1 if the key is not found
        }
        // Move the accessed item to the front of the list
        cacheList.splice(cacheList.begin(), cacheList, mpp[key]);
        return mpp[key]->second;
    }

    void put(int key, int value)
    {
        // If the key exists, update it and move it to the front
        if (mpp.find(key) != mpp.end()) 
        {
            cacheList.splice(cacheList.begin(), cacheList, mpp[key]);
            mpp[key]->second = value;
            return;
        }
        // If the cache is at capacity, remove the least recently used item
        if (cacheList.size() == capacity) {
            int lruKey = cacheList.back().first;
            cacheList.pop_back();
            mpp.erase(lruKey);
        }
        // Insert the new key-value pair at the front of the list
        cacheList.emplace_front(key, value);
        mpp[key] = cacheList.begin();
    }

private:
    int capacity;
    std::list<std::pair<int, int>> cacheList; 
    // Stores key-value pairs in LRU order
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> mpp; // Maps keys to list iterators
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
