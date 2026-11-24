***Problem:***
```
Implement the RandomizedSet class:

- RandomizedSet() Initializes the RandomizedSet object.
- bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
- bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
- int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works in average O(1) time complexity.
```



***Complexity:***
```
       Time Complexity: O(1) for all
       Space Complexity: O(n)
```



***Code:***
```cpp
#include <vector>
#include <unordered_map>
#include <random>

class RandomizedSet {
private:
    std::vector<int> nums_;                          // Stores the elements
    std::unordered_map<int, size_t> val_to_index_;  // Maps value -> index in nums_
    std::mt19937 gen_{std::random_device{}()};      // Random number generator

public:
    RandomizedSet() = default;

    bool insert(int val) {
        if (val_to_index_.count(val)) return false; // Already present
        nums_.push_back(val);
        val_to_index_[val] = nums_.size() - 1;
        return true;
    }

    bool remove(int val) {
        auto it = val_to_index_.find(val);
        if (it == val_to_index_.end()) return false; // Not present

        size_t idx = it->second;
        int last_val = nums_.back();

        // Move last element to idx position
        nums_[idx] = last_val;
        val_to_index_[last_val] = idx;

        nums_.pop_back();
        val_to_index_.erase(it);

        return true;
    }

    int getRandom() {
        std::uniform_int_distribution<size_t> dist(0, nums_.size() - 1);
        return nums_[dist(gen_)];
    }
};
```


***Testcases:***
```
Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); // 2 was already in the set, so return false.
randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
```
