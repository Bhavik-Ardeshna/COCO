#include <bits/stdc++.h>
using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define forrr(i, n) for (int i = 1; i <= n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

class Graph
{
public:
    int size;
    map<int, bool> visited;
    map<int, list<int>> adj;

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void Iterative_BFS(int s)
    {
        vector<bool> visited(size, false);

        list<int> queue;

        visited[s] = true;
        queue.push_back(s);

        while (!queue.empty())
        {
            s = queue.front();
            cout << s << " ";
            queue.pop_front();

            for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.size = 6;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Iterative Depth First Traversal \n";
    g.Iterative_BFS(2);
    cout << endl;
    return 0;
}