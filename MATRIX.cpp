#include <iostream>
#include <limits>

using namespace std;

void PRINT_OPTIMAL_PARENS(int s[][4], int i, int j) {
  if (i == j)
    cout << "A" << i;
  else {
    cout << "(";
    PRINT_OPTIMAL_PARENS(s, i, s[i][j]); 
    PRINT_OPTIMAL_PARENS(s,s[i][j] + 1, j);
    cout << ")";
  }
}



int MatrixChainOrder(int p[], int n) {
    int m[n][n]; 
    int s[n][4]; 

    
    for (int i = 0; i < n; i++) {
        m[i][i] = 0;
    }


    for (int l = 2; l < n; l++) {
       
        for (int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX; 

            
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q; // Update minimum cost
                    s[i][j] = k; // Store split point
                   	PRINT_OPTIMAL_PARENS(s, i, j);
                }
                
            }
            
        }
    }

 

    // Return minimum cost for entire chain
    return m[1][n - 1];
}

int main() {
    int p[] = {1, 2, 3, 4}; // Dimensions of matrices
    int n = sizeof(p) / sizeof(p[0]) - 1; // Subtract 1 to get the actual size of the array

    int minCost = MatrixChainOrder(p, n);

    cout << "\nMinimum number of scalar multiplications: " << minCost << endl;

    return 0;
}
