// Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
// Space Complexity: O(V). Since an extra visited array is needed of size V.

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

    void Recursive_DFS(int v)
    {
        visited[v] = true;
        cout << v << " ";
        // Explore all the new node and leave its remaining unvisited note it will trace back
        // Always explore new and forget previous for some time
        // Like playboy
        for (auto i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if (!visited[*i])
            {
                Recursive_DFS(*i);
            }
        }
    }

    void Iterative_DFS(int v)
    {
        vector<bool> visited(size, false);
        stack<int> st;

        st.push(v);

        while (!st.empty())
        {
            int temp = st.top();
            st.pop();

            if (!visited[temp])
            {
                cout << temp << " ";
                visited[temp] = true;
            }
            for (auto i = adj[temp].begin(); i != adj[temp].end(); i++)
            {
                if (!visited[*i])
                {
                    st.push(*i);
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.size = 5;
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);

    cout << "Following is Recursive Depth First Traversal \n";
    g.Recursive_DFS(0);
    cout << "\nFollowing is Iterative Depth First Traversal \n";
    g.Iterative_DFS(0);
    cout << endl;
    return 0;
}