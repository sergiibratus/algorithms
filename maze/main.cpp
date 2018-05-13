#include "bfs.h"
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "You have to pass the filename" << std::endl;
        return -1;
    }

    std::string filename = std::string(argv[1]);
    std::ifstream data(filename);

    std::vector<std::vector<char>> maze;
    std::string line;
    while (std::getline(data,line))
        maze.push_back(std::vector<char>(line.begin(), line.end()));

    std::cout << "Starting..." << std::endl;
    shortestPath(maze);
    return 0;
}
