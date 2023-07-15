#include <iostream>
#include <vector>

/**
 * この実装では訪問済みのノードを追跡するために
 * Closedリストに相当するvisited配列を利用しています。
 * Openリストは、まだ訪問していないが訪問予定のノードを
 * 保持するリストで、DFSでは通常スタック(LIFO)を使用します。
 */
// Define the adjacency list
std::vector<int> adj[4];

// Function to add an edge between two nodes
void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Define the visited list
std::vector<bool> visited(4, false);
// std::cout << visited << std::endl;

// DFS function
void dfs(int node)
{
    visited[node] = true;
    std::cout << node << " ";

    std::vector<int>::iterator i;
    for (i = adj[node].begin(); i != adj[node].end(); ++i)
    {
        if (!visited[*i])
        {
            dfs(*i);
        }
    }
}

int main()
{
    // Add edges
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 0);

    // Run DFS
    dfs(0);

    return 0;
}
