#include <iostream>
#include <queue>

int shortestPath(const std::vector<std::vector<char>>& maze) {
    if (maze.empty() || maze[0].empty()) {
        std::cout << "Cannot find the path for the empty array" << std::endl;
        return -1;
    }

    int start_i = -1;
    int start_j = -1;

    for (int i = 0; i < maze.size() && start_i == -1; ++i)
        for (int j = 0; j < maze[0].size(); ++j)
            if (maze[i][j] == 'S') {
                start_i = i;
                start_j = j;
                break;
            }

    if (start_i == -1) {
        std::cout << "The source point was not found" << std::endl;
        return -1;
    }

    struct point {
        int i;
        int j;
        int level;
    };

    std::vector<std::vector<int>> visited(maze.size(), std::vector<int>(maze[0].size(), 0));
    // Here, start_i and start_j represent the starting point of the maze
    std::queue<point> q;
    q.push(point{start_i, start_j, 0});
    visited[start_i][start_j] = 1;

    while (!q.empty()) {
        point p = q.front();
        q.pop();

        if (p.i >= maze.size() || p.j >= maze[0].size()
                || maze[p.i][p.j] == '|' || maze[p.i][p.j] == '-'
                || maze[p.i][p.j] == '+')
            continue;

        if (maze[p.i][p.j] == 'E') {
            std::cout << "Found the exit point at " << p.i << ","
                << p.j << " with distance = " << p.level << std::endl;

            return p.level;
        }

        // Here we are sitting at the dot. add all neighbours
        if (visited[p.i + 1][p.j] != 1) {
            visited[p.i + 1][p.j] = 1;
            q.push(point{p.i + 1, p.j, p.level + 1});
        }
        if (visited[p.i - 1][p.j] != 1) {
            visited[p.i - 1][p.j] = 1;
            q.push(point{p.i - 1, p.j, p.level + 1});
        }
        if (visited[p.i][p.j + 1] != 1) {
            visited[p.i][p.j + 1] = 1;
            q.push(point{p.i, p.j + 1, p.level + 1});
        }
        if (visited[p.i][p.j - 1] != 1) {
            visited[p.i][p.j - 1] = 1;
            q.push(point{p.i, p.j - 1, p.level + 1});
        }
    }

    std::cout << "The end point was not found" << std::endl;
    return -1;
}

