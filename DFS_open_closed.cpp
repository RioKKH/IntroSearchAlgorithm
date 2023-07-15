#include <iostream>
#include <vector>
#include <stack>

/**
 * 深さ優先探索(Depth First Search)
 * 深さ優先探索は、グラフや木の探索に利用されるアルゴリズムの一つで、
 * その名の通り「深さ」を優先して探索を行います。具体的には、現在の
 * ノードから訪問可能なノードがある限り、まずそのノードを訪問し、その
 * ノードからさらに訪問可能なノードを探し…という手順を繰り返します。
 * 訪問可能なノードがなくなったら、一つ前のノードに戻り（バックトラック）、
 * そこから新なノードを探します。
 *
 * DFSの特徴は以下の通りです。
 * １．完全性：全てのノードが有限で、かつ全てのエッジのコストが正（ゼロでない）
 * であれば、DFSは必ず解を見つける事が出来ます。
 * ２．非最適性：DFSは最初に見つけた解が最適解であるとは限りません。これは、
 * DFSが深さを優先するために、最初に見つけた解が最適経路であるとは限らない
 * からです。
 * ３．空間効率性：DFSは探索の途中経過をスタックというデータ構造に保存します。
 * このため、探索が深くなるほど必要なメモリが増えます。しかし、全てのノードを
 * 保存するわけではないため、空間効率は比較的良いといえます。
 * ４．時間効率性：DFSの時間効率性は、探索すべきノードとエッジの数に依存します。
 * 全てのノードとエッジを一度ずつ訪問するため、時間複雑度はO(V + E)となります。
 * Vはノード数、Eはエッジ数。
 *
 * 以上がDFSの基本的な理論的背景になります。
 *
 * 以下のコードではdfs関数内でOpenリスト(スタックs)とClosedリスト(visited配列)を
 * 明示的に使用しています。まずスタートノードをOpenリストに追加します。Openリスト
 * が空になるまで以下の操作を繰り返します：Openリストのトップのノードを取り出し、
 * そのノードがまだ訪問されていなければそのノードを訪問し、そのノードにリンセスする
 * 未訪問のノードを全てOpenリストに追加します。
 *
 * Cloesdリストは深さ優先探索（DFS）において重要な役割を果たします。Closedリスト
 * （この場合はvisited配列）は、すでに訪問済みのノードを追跡するために使用されます。
 *
 * DFSでは、現在のノードから訪問可能なノードがある限り、まずそのノードを訪問し、
 * そのノードからさらに訪問可能なノードを探します。訪問可能なノードがなくなったら、
 * 一つ前のノードに戻り（バックトラック）、そこから新なノードを探します。
 * このプロセスの中で、同じノードを何度も訪問することを防ぐためにClosedリストが
 * 必要となります。Closedリストが無ければ、DFSは無限ループに陥る可能性が有ります
 * （特に循環グラフの場合）。したがって、各ノードを訪問する際にはClosedリストを
 * チェックし、すでに訪問済みのノードを再訪問することを避けます。
 */


/**
 * @brief Add an edge between two nodes in the adjacency list
 *
 * @param u First node
 * @param v Second node
 */
void addEdge(std::vector<int> adj[], int u, int v)
// void addEdge(std::vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

/**
 * @brief Perform Depth-First Search (DFS) from a given node
 *
 * @param adj Adjacency list representing the graph
 * @param start Starting node for the DFS
 */
void dfs(std::vector<int> adj[], int start)
{
    std::vector<bool> visited(adj->size(), false); // Closed list
    std::stack<int> s; // Open list (stack)

    s.push(start); // Add the start node to the Open list

    while (!s.empty())
    {
        int node = s.top();
        s.pop();

        if (!visited[node])
        {
            std::cout << node << " ";
                visited[node] = true;

                // iに格納されているのはadj[node]forお各要素(node隣接するノード)
                // を指すイテレータ。*iを使用することで、そのイテレータが指す要素
                // (ノード)を参照できる。つまり、イテレータはポインタのように振る舞う
                // オブジェクトである。
                //
                // 以下のコードが深さ優先探索の中心的な部分で、現在のノードから訪問
                // 可能なすべてのノードを調べ、未訪問のノードをスタックに追加する役割を
                // はたしている。
                //
                // nodeに隣接するすべてのノードを順に調べるループ。adj[node]は隣接する
                // ノードのリスト（ベクター）を表し、begein()とend()はそれぞれリストの
                // 最初と最後を指すイテレータを返します。autoキーワードはC++11から導入
                // された機能で、変数の型を自動的に推論する。この場合、iの型は
                // vector<int>::iteratorと推論される
                for (auto i = adj[node].begin(); i != adj[node].end(); ++i)
                {
                    if (!visited[*i]) // ノードが未訪問であれば
                    {
                        // 現在調べているノードをスタックsに追加する。
                        // 未訪問のノードを訪問予定としてスタックに追加する
                        s.push(*i);
                    }
                }
        }
    }
}

int main()
{
    int V = 4;
    std::vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 0);

    dfs(adj, 0);

    return 0;
}
