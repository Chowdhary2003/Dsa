***Problem:***
```
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.
```



***Complexity:***
```
       Time Complexity: O(N * M α(N*M) + S log S)
       Space Complexity: O(N * M)
```



***Code:***
```cpp
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class UnionFind {
    vector<int> parent;
public:
    UnionFind(int n) : parent(n) {
        for(int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }
    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if(pa != pb)
            parent[pa] = pb;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToID;  // email -> unique ID
        unordered_map<string, string> emailToName;  // email -> name

        int id = 0;
        // Assign unique ID to every email
        for (const auto& account : accounts) {
            const string& name = account[0];
            for (int i = 1; i < (int)account.size(); ++i) {
                const string& email = account[i];
                if (!emailToID.count(email)) {
                    emailToID[email] = id++;
                    emailToName[email] = name;
                }
            }
        }

        UnionFind uf(id);

        // Union emails in the same account
        for (const auto& account : accounts) {
            int firstEmailID = emailToID[account[1]];
            for (int i = 2; i < (int)account.size(); ++i) {
                uf.unite(firstEmailID, emailToID[account[i]]);
            }
        }

        // Group emails by root parent ID
        unordered_map<int, vector<string>> groups;
        for (const auto& [email, idx] : emailToID) {
            int parent = uf.find(idx);
            groups[parent].push_back(email);
        }

        // Prepare output
        vector<vector<string>> mergedAccounts;
        for (auto& [parent, emails] : groups) {
            sort(emails.begin(), emails.end());
            vector<string> account;
            account.push_back(emailToName[emails[0]]); // name
            account.insert(account.end(), emails.begin(), emails.end());
            mergedAccounts.push_back(move(account));
        }

        return mergedAccounts;
    }
};
```


***Testcases:***
```
Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
```

```
Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
```
