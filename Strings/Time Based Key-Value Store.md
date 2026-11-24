***Problem:***
```
Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:
- TimeMap() Initializes the object of the data structure.
- void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
- String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
```



***Complexity:***
```
       Time Complexity: set - O(1), get - O(log N)
       Space Complexity: O(1)
```



***Code:***
```cpp
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

class TimeMap {
private:
    // Map from key -> vector of (timestamp, value), sorted by timestamp ascending
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> store;

public:
    TimeMap() = default;

    void set(const std::string& key, const std::string& value, int timestamp) {
        // Append the new timestamp-value pair
        store[key].emplace_back(timestamp, value);
    }

    std::string get(const std::string& key, int timestamp) {
        auto it = store.find(key);
        if (it == store.end()) return "";

        const auto& vec = it->second;

        // Binary search for the largest timestamp <= query timestamp
        // Use std::upper_bound with a custom comparator
        auto comp = [](const std::pair<int, std::string>& p, int ts) {
            return p.first <= ts;
        };

        // upper_bound returns iterator to first element > timestamp,
        // so we want element just before that (if any)
        auto ub = std::upper_bound(vec.begin(), vec.end(), timestamp,
            [](int ts, const std::pair<int, std::string>& p) {
                return ts < p.first;
            });

        if (ub == vec.begin()) {
            // All timestamps are greater than query timestamp
            return "";
        }

        // Move iterator back to largest timestamp <= query timestamp
        --ub;
        return ub->second;
    }
};
```


***Testcases:***
```
Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]

Explanation
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
timeMap.get("foo", 1);         // return "bar"
timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
timeMap.get("foo", 4);         // return "bar2"
timeMap.get("foo", 5);         // return "bar2"
```
