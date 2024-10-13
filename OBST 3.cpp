#include <iostream>
#include <limits>

using namespace std;

const int MAX_N = 100;

int e[MAX_N + 2][MAX_N + 2]; // Increased size by 1 for both dimensions
int w[MAX_N + 2][MAX_N + 2]; // Increased size by 1 for both dimensions
int root[MAX_N + 1][MAX_N + 1];

void optimal(const int p[], const int q[], int n, int e[][MAX_N + 2], int w[][MAX_N + 2], int root[][MAX_N + 1]) {
    // Initialize tables
    for (int i = 1; i <= n + 1; ++i) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    // Fill the tables using dynamic programming
    for (int l = 0; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l;
            e[i][j] = INT_MAX; // Use INT_MAX from <limits>
            w[i][j] = w[i][j - 1] + p[j - 1] + q[j];

            for (int r = i; r <= j; ++r) {
                int t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }
}

int main() {
    int p[] = {1, 4, 2, 1};
    int q[] = {4, 2, 4, 1, 1};
    int n = sizeof(p) / sizeof(p[0]);

    optimal(p, q, n - 1, e, w, root);

    cout << "Expected Costs (e):\n";
    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= n ; ++j) { // Corrected index to n+1
            cout << e[i][j] << "     ";
        }
        cout << endl;
    }

    cout << "\nRoots (root):\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << root[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
