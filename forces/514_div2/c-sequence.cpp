#include <iostream>

using namespace std;

void solve(int n, int mul) {
    if (n == 1) {
        cout << " " << 1 * mul << endl;
        return;
    }
    if (n == 2) {
        cout << " " << 1 * mul << " " << 2 * mul << endl;
        return;
    }
    if (n == 3) {
        cout << " " << 1 * mul << " " << 1 * mul << " " << 3 * mul << endl;
        return;
    }

    for (int i = 0; i < (n  + 1) / 2; i++) {
        cout << " " << mul;
    }

    solve(n / 2, mul * 2);
}

int main() {
    int N = 0;
    cin >> N;

    solve(N, 1);

    return 0;
}
