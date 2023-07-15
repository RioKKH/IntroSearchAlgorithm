/**
 * @file Breadth-First Search)
 *
 * 幅優先探索（BFS）は、グラフデータ構造を検索するために使用されるアルゴリズムで、
 * グラフのルートから始まり、現在の深さレベルのすべてのノードを訪問した後、次の深さ
 * レベルのノードを訪問します。
 * BFSは、グラフの幅優先探索と木の幅優先探索が似ています。ただし、グラフにはサイクル
 * が含まれる可能性があるため、同じノードに再度到達する可能性があります。
 * これを避けるために、頂点を訪問済みと未訪問の2つのカテゴリに分けます。
 * 訪問済みの頂点をマークするために、boolean型のvisited配列が使用されます。
 * すべての頂点が開始頂点から到達可能であると仮定して、単純化します。
 * BFSは、探索のためにキューデータ構造を使用します。
 *
 * BFSの動作は以下の通りです：
 * 1. ルートから始めて、特定のレベルのすべてのノードを最初に訪問し、次に、すべての
 * ノードが訪問されるまで、次のレベルのノードを走査します。
 * 2. これを行うために、キューが使用されます。現在のレベルのすべての隣接未訪問ノードが
 * キューにプッシュされ、現在のレベルのノードが訪問済みとマークされ、キューからポップされます。
 *
 * BFSの時間計算量はO(V+E)で、Vはノードの数、Eはエッジの数です。補助空間はO(V)です。
 * BFSは、最短経路問題や迷路の解など、様々な問題を解くことができます。
 * また、ソーシャルネットワークの友人探索やWebクローリングなど、様々な応用例があります。
 */

#include <iostream>
#include <list>

//* This class represents a directed graph using adjacency list representation
class Graph
{
private:
    int V; ///< No. of vertices
    std::list<int> *adj; ///< Pointer to an array containing adjacency lists

public:
    Graph(int V); ///< Constructor

    //* function to add an edge to graph
    void addEdge(int v, int w);

    //* prints BFS traversal from a given source s
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); ///< Add w to v's list.
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    // Create a queue for BFS
    std::list<int> queue;

    // Mark the current notde as visited and enqueue it
    // BFSメソッドでは、幅優先探索を実行しています。まず、すべての頂点を未訪問とマークするための
    // ブール型の配列visitedを作成しています。次にBFSのためのキューを作成し、開始頂点を訪問済み
    // とマークしてキューに追加しています。
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent vertices of a vertex
    // 明示的に宣言すればこうなる、ということかな。
    // 普通はauto i = adj=[s].begin()と書いてしまうと思う。
    std::list<int>::iterator i;

    // その後、キューがからになるまで以下の処理を繰り返しています。
    // １．キューの先頭の頂点を取り出し、その頂点を出力します。
    // ２．取り出した頂点のすべての隣接頂点について、未訪問であれば訪問済み
    //     とマークしてキューに追加します。
    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        std::cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex s. 
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        // for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                queue.push_back(*i);
                visited[*i] = true;
            }
        }
    }
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Following is Breadth First Traversal (starting from vertex 2)\n";
    g.BFS(2);

    return 0;
}


