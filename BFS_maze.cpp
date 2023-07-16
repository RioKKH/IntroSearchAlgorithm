#include <iostream>
#include <queue>
#include <cmath>

constexpr int ROW = 9;
constexpr int COL = 10;

typedef std::pair<int, int> Pair;
typedef std::pair<double, std::pair<int, int>> pPair;

class MazeSolver
{
private:
    struct cell
    {
        int parent_i;
        int parent_j;
        double f;
        double g;
        double h;
    };

    int grid[ROW][COL];
    Pair src, dest;

public:
    MazeSolver(int g[ROW][COL], Pair s, Pair d) : src(s), dest(d)
    {
        for (int i = 0; i < ROW; ++i)
        {
            for (int j = 0; j < COL; ++j)
            {
                grid[i][j] = g[i][j];
            }
        }
    }

    bool isValid(int row, int col);
    bool isUnBlocked(int row, int col);
    bool isDestination(int row, int col);
    double calculateHValue(int row, int col);
    /**
     * C++では、関数の引数として多次元配列を渡すとき、最初の次元のサイズは省略
     * することが出来ます。これはC++の配列が実際にはポインタであり、関数に渡される
     * のは配列の先頭要素へのポインタであるためです。従って、最初の次元のサイズは
     * 実際には関数には必要ありません。しかし、2次元以上の配列の場合、2つ目以降の
     * 次元のサイズは必要です。これは、配列の要素にアクセスするためには、全ての
     * 次元のサイズを知る必要があるからです。したがって、
     * void tracePath(cell cellDetails[][COL]);
     * という宣言は、cellDetailsが2次元配列で、2つ目の次元のサイズがCOLである事を
     * 示しています。
     */
    void tracePath(cell cellDetails[][COL]);
    void aStarSearch();
};

bool MazeSolver::isValid(int row, int col)
{
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

bool MazeSolver::isUnBlocked(int row, int col)
{
    if (grid[row][col] == 1)
    {
        return (true);
    }
    else
    {
        return (false);
    }
}

bool MazeSolver::isDestination(int row, int col)
{
    if (row == dest.first && col == dest.second)
    {
        return (true);
    }
    else
    {
        return (false);
    }
}

double MazeSolver::calculateHValue(int row, int col)
{
    return ((double)sqrt(  (row - dest.first)  * (row - dest.first)
                         + (col - dest.second) * (col - dest.second)));
}

void MazeSolver::tracePath(cell cellDetails[][COL])
{
    std::cout << "The Path is ";
    int row = dest.first;
    int col = dest.second;

    std::stack<Pair> Path;


