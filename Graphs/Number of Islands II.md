# Number of Islands II

```cpp
/*
    Time complexity: O(n * m + q)
    Space complexity: O(n * m + q)

    Where 'n' and 'm' are the dimensions of the grid, and 'q' is the number of queries.
*/

struct DSU
{
    vector<int> e;
    DSU(int N)
    {
        e = vector<int>(N, -1);
    }

    int get(int x)
    {
        return e[x] < 0 ? x : e[x] = get(e[x]);
    }

    bool same_set(int a, int b)
    {
        return get(a) == get(b);
    }

    int size(int x)
    {
        return -e[get(x)];
    }

    bool merge(int x, int y)
    {
        x = get(x);
        y = get(y);
        if (x == y)
            return false;
        if (e[x] > e[y])
            swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

vector<int> numberOfIslandII(int n, int m, vector<vector<int>>& queries, int q)
{
    DSU d(n * m);

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<int> ans;
    int count = 0;

    for(vector<int>& query : queries)
    {
        int x = query[0], y = query[1];

        grid[x][y] = 1;
        count++;

        for(int i = 0; i < 4; i++)
        {
            int a = x + dx[i];
            int b = y + dy[i];

            if(a >= 0 && a < n && b >= 0 && b < m && grid[a][b] == 1)
            {
                if(!d.same_set(x * m + y, a * m + b))
                {
                    count--;
                    d.merge(x * m + y, a * m + b);
                }
            }
        }

        ans.push_back(count);
    }

    return ans;
}
```
