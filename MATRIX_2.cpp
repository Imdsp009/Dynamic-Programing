#include <iostream>
#include <limits>
#include <climits>

using namespace std;

// Function to print the optimal parenthesization
void printOptimalParenthesization(int s[][5], int i, int j) {
    if (i == j)
        cout << "A" << i + 1;
    else {
        cout << "(";
        printOptimalParenthesization(s, i, s[i][j]);
        printOptimalParenthesization(s, s[i][j] + 1, j);
        cout << ")";
    }
}

// Function to determine the minimum number of operations required
int matrixChainOrder(int p[], int n) {
    int m[n][n]; // Minimum number of operations
    int s[n][5]; // Split points

    for (int i = 0; i < n; ++i) {
        m[i][i] = 0;
    }

    for (int l = 1; l <= n; ++l) {
        for (int i = 0; i < n - l ; ++i) {
            int j = i + l ;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; ++k) {
                int q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    // Print the optimal parenthesization
    cout << "Optimal Parenthesization: ";
    printOptimalParenthesization(s, 0, n - 1);
    cout << endl;

    return m[0][n - 1];
}

int main() {
    int p1[] = {40, 20, 30, 10, 30};
    int n1 = sizeof(p1) / sizeof(p1[0]) - 1;
    cout << "Minimum number of scalar multiplications: " << matrixChainOrder(p1, n1) << endl;

    int p2[] = {10, 20, 30, 40, 30};
    int n2 = sizeof(p2) / sizeof(p2[0]) - 1;
    cout << "Minimum number of scalar multiplications: " << matrixChainOrder(p2, n2) << endl;

    return 0;
}
