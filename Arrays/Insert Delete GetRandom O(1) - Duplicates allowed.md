***Problem:***
```
RandomizedCollection is a data structure that contains a collection of numbers, possibly duplicates (i.e., a multiset). It should support inserting and removing specific elements and also reporting a random element.

Implement the RandomizedCollection class:
- RandomizedCollection() Initializes the empty RandomizedCollection object.
- bool insert(int val) Inserts an item val into the multiset, even if the item is already present. Returns true if the item is not present, false otherwise.
- bool remove(int val) Removes an item val from the multiset if present. Returns true if the item is present, false otherwise. Note that if val has multiple occurrences in the multiset, we only remove one of them.
- int getRandom() Returns a random element from the current multiset of elements. The probability of each element being returned is linearly related to the number of the same values the multiset contains.

You must implement the functions of the class such that each function works on average O(1) time complexity.

Note: The test cases are generated such that getRandom will only be called if there is at least one item in the RandomizedCollection.
```



***Complexity:***
```
       Time Complexity: O(1) for all
       Space Complexity: O(n) for storing all
```



***Code:***
```cpp
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <random>

class RandomizedCollection {
private:
    std::vector<int> nums; // store elements
    std::unordered_map<int, std::unordered_set<int>> idx_map; // val -> set of indices in nums
    
    std::mt19937 gen; // random number generator
    
public:
    RandomizedCollection() : gen(std::random_device{}()) {}

    bool insert(int val) {
        bool not_present = idx_map[val].empty();
        nums.push_back(val);
        idx_map[val].insert(nums.size() - 1);
        return not_present;
    }

    bool remove(int val) {
        auto it = idx_map.find(val);
        if (it == idx_map.end() || it->second.empty()) return false;

        int remove_idx = *it->second.begin();
        int last_idx = nums.size() - 1;
        int last_val = nums.back();

        // Remove the index from val's set first
        it->second.erase(remove_idx);

        if (remove_idx != last_idx) {
            // Move last_val to remove_idx
            nums[remove_idx] = last_val;

            // Update the index set for last_val
            idx_map[last_val].insert(remove_idx);
            idx_map[last_val].erase(last_idx);
        }
        // Remove last element from vector
        nums.pop_back();

        // Clean up map if empty
        if (it->second.empty()) {
            idx_map.erase(it);
        }

        return true;
    }

    int getRandom() {
        std::uniform_int_distribution<> dist(0, nums.size() - 1);
        return nums[dist(gen)];
    }
};

```


***Testcases:***
```
Input
["RandomizedCollection", "insert", "insert", "insert", "getRandom", "remove", "getRandom"]
[[], [1], [1], [2], [], [1], []]
Output
[null, true, false, true, 2, true, 1]

Explanation
RandomizedCollection randomizedCollection = new RandomizedCollection();
randomizedCollection.insert(1);   // return true since the collection does not contain 1.
                                  // Inserts 1 into the collection.
randomizedCollection.insert(1);   // return false since the collection contains 1.
                                  // Inserts another 1 into the collection. Collection now contains [1,1].
randomizedCollection.insert(2);   // return true since the collection does not contain 2.
                                  // Inserts 2 into the collection. Collection now contains [1,1,2].
randomizedCollection.getRandom(); // getRandom should:
                                  // - return 1 with probability 2/3, or
                                  // - return 2 with probability 1/3.
randomizedCollection.remove(1);   // return true since the collection contains 1.
                                  // Removes 1 from the collection. Collection now contains [1,2].
randomizedCollection.getRandom(); // getRandom should return 1 or 2, both equally likely.
```
