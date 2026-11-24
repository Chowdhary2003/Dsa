***Problem:***
```
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
```



***Complexity:***
```
       Time Complexity: O(N + E)
       Space Complexity: O(N)
```



***Code:***
```cpp
// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() : val(0), neighbors() {}
    Node(int _val) : val(_val), neighbors() {}
    Node(int _val, std::vector<Node*> _neighbors)
        : val(_val), neighbors(_neighbors) {}
};

class Solution {
public:
    // Hash map to keep track of cloned nodes
    std::unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        return dfs(node);
    }

private:
    Node* dfs(Node* node) {
        // If the node was already cloned, return it
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // Create a clone node
        Node* clone = new Node(node->val);
        visited[node] = clone;  // Mark as visited

        // Clone neighbors recursively
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor));
        }

        return clone;
    }
};
```


***Testcases:***

<img width="1369" height="1387" alt="Screenshot 2025-07-11 083044" src="https://github.com/user-attachments/assets/0a9dd2c4-6f86-49fe-98bd-acb69d9b0acc" />
