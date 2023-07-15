#include <iostream>
#include <vector>
#include <stack>

/**
 * @file Maze solved by using DFS.
 *
 * 迷路問題を解くためには、迷路をグラフとして表現し、深さ優先探索（DFS）を
 * 適用することが一般的です。迷路の各セルをノードとし、隣接するセル間に
 * エッジを引くことでグラフを作ります。
 *
 * 以下に、迷路問題を解くためのDFSのC++実装を示します。このコードでは、迷路は
 * 2次元配列として表現され、0は通路、１は壁を笑わします。スタート地点は(0, 0)、
 * ゴール地点は(n-1, m-1)とします。
 */

// Directions to move from the current cell
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// Depth-First Search (DFS) function to solve the maze
bool dfs(std::vector<std::vector<int>>& maze, int x, int y,
        std::vector<std::pair<int, int>>& path)
{
    int n = maze.size();
    int m = maze[0].size();

    // Check if the current position is the goal
    if (x == n - 1 && y == m -1)
    {
        maze[x][y] = 2; // Mark the path
        path.push_back({x, y}); // Add the goal to the path
        return true;
    }

    // Mark the current cell as visited.
    maze[x][y] = 2;

    // Try all possible movements from the current position
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // Check if the new position is valid and not visited
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0)
        {
            path.push_back({x, y}); // Add the current cell to the path
            // DFSは最適的な構造を持っている為、再帰関数を用いて簡潔に
            // 実装することが出来る。以下の部分で再帰呼び出しを行っている。
            if (dfs(maze, nx, ny, path))
            {
                return true;
            }
            path.pop_back(); // Remove the current cell from the path
        }
    }
    return false;
}

int main()
{
    // Define the maze
    std::vector<std::vector<int>> maze = {
        {0, 0, 1, 0},
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 0, 0, 0}
    };

    // Vector to store the path
    std::vector<std::pair<int, int>> path;

    // Solve the maze
    if (dfs(maze, 0, 0, path))
    {
        std::cout << "Path found!" << std::endl;
        for (auto& p : path)
        {
            std::cout << '(' << p.first << ',' << p.second << ')';
        }
        std::cout << '\n';
    }
    else
    {
        std::cout << "No path found." << std::endl;
    }

    return 0;
}
