# Pair with given target

> Converted from the original standalone C++ source. The implementation is preserved verbatim.

## Complexity

The original source does not document complexity; analyze it after reviewing the algorithm.

## C++ solution

```cpp
class Solution {
public:
    bool isPairPresent(Node* root, int target) {
        stack<Node*> stack1, stack2;
        Node* curr1 = root;
        Node* curr2 = root;

        while (true) {
            // In-order traversal from left to right
            while (curr1 != nullptr) {
                stack1.push(curr1);
                curr1 = curr1->left;
            }

            // In-order traversal from right to left
            while (curr2 != nullptr) {
                stack2.push(curr2);
                curr2 = curr2->right;
            }

            if (stack1.empty() || stack2.empty())
                break;

            Node* node1 = stack1.top();
            Node* node2 = stack2.top();

            if (node1 == node2)
                break;

            int sum = node1->data + node2->data;

            if (sum == target)
                return true;
            else if (sum < target) {
                stack1.pop();
                curr1 = node1->right;
            } else {
                stack2.pop();
                curr2 = node2->left;
            }
        }

        return false;
    }
};
```

## Review notes

- Original C++ source text is preserved in the code block.
- Check judge-provided headers, node definitions, and function signatures before standalone compilation.
- Add intuition, dry run, and test cases after confirming the original problem requirements.
