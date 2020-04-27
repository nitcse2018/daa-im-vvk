#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{

    map<T, list<T>> l;

public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T src, map<T, int> &visited)
    {
        cout << src << ", ";
        visited[src] = true;

        for (auto node : l[src])
        {
            if (!visited[node])
            {
                dfs_helper(node, visited);
            }
        }
    }

    void dfs(T src)
    {
        map<T, int> visited;
        for (auto p : l)
        {
            visited[p.first] = false;
        }

        dfs_helper(src, visited);
    }
};

int main()
{
    // Graph<int> g;
    // g.addEdge(0, 1);
    // g.addEdge(1, 2);
    // g.addEdge(2, 3);
    // g.addEdge(3, 4);
    // g.addEdge(4, 5);

    // g.dfs(0);

    Graph<string> g;
    g.addEdge("A", "B");
    g.addEdge("B", "C");
    g.addEdge("C", "D");
    g.addEdge("D", "E");
    g.addEdge("E", "F");

    g.dfs("A");

    return 0;
}