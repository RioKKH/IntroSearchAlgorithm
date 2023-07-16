#include <iostream>
#include <list>
#include <vector>

class Graph
{
private:
    int V;
    std::list<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
    void DFSUtil(int v, std::vector<bool>& visited);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

/**
 * この関数は、探索を開始する頂点vと、各頂点が訪問済みかどうかを追跡するための
 * ブール型のベクトルvisitedを引数にとります。
 * 関数はまず、頂点vを訪問済みとマークし（visited[v] = true;）、その頂点の番号を
 * 出力します (std::cout << v << " ";)
 * 次に、頂点vの全ての隣接頂点を調べます。これは、隣接リストadj[v]を通じて行われます。
 * このリストの各頂点について、その頂点がまだ訪問されていない場合(if (!visited[*i]))、
 * 関数はその頂点に対して自身を再帰的に呼び出します(DFSUtil(*i, visited);)。
 * これにより、その頂点から到達可能な全ての頂点が深さ優先の順序で訪問されます。
 * この関数は、ＤＦＳの特性を反映しています。つまり、可能な限り深く探索を進め、
 * それ以上進めなくなったら一つ前の頂点に戻って別の経路を探索します。これは関数が
 * 自身を再帰的に呼び出す事で実現されています。
 */
void Graph::DFSUtil(int v, std::vector<bool>& visited)
{
    visited[v] = true;
    std::cout << v << " ";

    std::list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
        {
            DFSUtil(*i, visited);
        }
    }
}

void Graph::DFS(int v)
{
    std::vector<bool> visited(V, false);
    DFSUtil(v, visited);
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Following is Depth First Traversal (starting from vertex 2)" << std::endl;
    g.DFS(2);

    return 0;
}
