#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int v;
    list<pair<int, int>> *adj;

    Graph(int v)
    {
        this->v = v;
        adj = new list<pair<int, int>>[v];
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    int findMinVertex(int *weight, bool *visited, int v)
    {
        int minVertex = -1;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i] and (minVertex == -1 or weight[i] < weight[minVertex]))
            {
                minVertex = i;
            }
        }
        return minVertex;
    }

    void Prims()
    {
        bool *visited = new bool[v];
        int *parent = new int[v];
        int *weight = new int[v];

        for (int i = 0; i < v; i++)
        {
            weight[i] = INT_MAX;
            visited[i] = false;
        }

        weight[0] = 0;
        parent[0] = -1;

        for (int i = 0; i < v; i++)
        {
            int minVertex = findMinVertex(weight, visited, v);
            visited[minVertex] = true;
            for (auto nbr : adj[minVertex])
            {
                if (!visited[nbr.first] and nbr.second < weight[nbr.first])
                {
                    parent[nbr.first] = minVertex;
                    weight[nbr.first] = nbr.second;
                }
            }
        }

        for (int i = 1; i < v; i++)
        {
            cout << i << "--" << parent[i] << " with weight " << weight[i] << endl;
        }
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    Graph g(n);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    g.Prims();
    return 0;
}