***Problem:***
```
We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
```



***Complexity:***
```
       Time Complexity: O(n)
       Space Complexity: O(n)
```



***Code:***
```cpp
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::vector<int> stack;

        for (int asteroid : asteroids) {
            bool destroyed = false;

            while (!stack.empty() && asteroid < 0 && stack.back() > 0) {
                if (stack.back() < -asteroid) {
                    stack.pop_back();  // Current asteroid survives, continue
                } else if (stack.back() == -asteroid) {
                    stack.pop_back();  // Both destroyed
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;  // Incoming asteroid destroyed
                    break;
                }
            }

            if (!destroyed) {
                stack.push_back(asteroid);
            }
        }

        return stack;
    }
```


***Testcases:***
```
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
```

```
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
```

```
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
```
