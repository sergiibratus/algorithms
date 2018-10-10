#include <iostream>
#include <vector>

using namespace std;

int main () {
    int N = 0, M = 0;
    cin >> N >> M;
    vector<vector<char>> v(N, vector<char>(M));
    vector<vector<bool>> b(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {
            if (v[i-1][j-1] != '#' ||
                v[i-1][j] != '#' ||
                v[i-1][j+1] != '#' ||
                v[i][j+1] != '#' ||
                v[i+1][j+1] != '#' ||
                v[i+1][j] != '#' ||
                v[i+1][j-1] != '#' ||
                v[i][j-1] != '#')
                continue;

            b[i-1][j-1] = true;
            b[i-1][j] = true;
            b[i-1][j+1] = true;
            b[i][j+1] = true;
            b[i+1][j+1] = true;
            b[i+1][j] = true;
            b[i+1][j-1] = true;
            b[i][j-1] = true;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j] == '#' && b[i][j] == false) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    return 0;
}
