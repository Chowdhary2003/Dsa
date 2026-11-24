***Problem:***
```
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:
- LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
- int get(int key) Return the value of the key if the key exists, otherwise return -1.
- void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.
```



***Complexity:***
```
       Time Complexity: get: O(1), put: O(1)
       Space Complexity: O(capacity)
```



***Code:***
```cpp
#include <unordered_map>
#include <list>
#include <utility>

class LRUCache {
private:
    int capacity_;

    // Doubly linked list stores keys and values.
    // Front = most recently used, back = least recently used.
    std::list<std::pair<int, int>> cache_list_;

    // Map keys to their position (iterator) in the list.
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache_map_;

    // Move accessed node to front (MRU).
    void moveToFront(int key) {
        auto node_it = cache_map_[key];
        cache_list_.splice(cache_list_.begin(), cache_list_, node_it);
    }

public:
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        auto it = cache_map_.find(key);
        if (it == cache_map_.end()) return -1;

        // Move accessed node to front and return value.
        moveToFront(key);
        return cache_list_.begin()->second;
    }

    void put(int key, int value) {
        auto it = cache_map_.find(key);
        if (it != cache_map_.end()) {
            // Update value and move to front.
            it->second->second = value;
            moveToFront(key);
        } else {
            // Insert new node at front.
            cache_list_.emplace_front(key, value);
            cache_map_[key] = cache_list_.begin();

            // If capacity exceeded, remove LRU from back.
            if ((int)cache_map_.size() > capacity_) {
                auto lru = cache_list_.back();
                cache_map_.erase(lru.first);
                cache_list_.pop_back();
            }
        }
    }
};
```


***Testcases:***
```
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
```
