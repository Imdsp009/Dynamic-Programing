#include <iostream>

using namespace std;

const int MAX_N = 100; // Adjust this based on your expected number of keys

int e[MAX_N + 1][MAX_N + 1];
int root[MAX_N + 1][MAX_N + 1];

int sum(const int freq[], int i, int j) 
{ 
	int s = 0; 
	for (int k = i; k <= j; k++) 
	s += freq[k]; 
	return s; 
} 
void obst_dp(const int keys[], const int freq[], int n, int e[][MAX_N + 1], int root[][MAX_N + 1]) {

	int x;
    for (int i = 1; i <= n; ++i) {
        e[i][i] = freq[i - 1];
        root[i][i] = i;
    }

    for (int d = 1; d < n; ++d) {
        for (int i = 1; i <= n - d; ++i) {
            int j = i + d;
            int min_cost = INT_MAX;
            x=sum(freq,i,j);
            for (int r = i; r <= j; ++r) {
            	
                int cost = e[i][r - 1] + e[r + 1][j] ;
                if (cost < min_cost) {
                    min_cost = cost;
                    root[i][j] = r;
                }
            }
            e[i][j] = min_cost+x;
        }
    }
}


int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    obst_dp(keys, freq, n, e, root);

    cout << "Expected Costs (e):\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << e[i][j] << " ";
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
