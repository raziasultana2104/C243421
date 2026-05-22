#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string X;
    cin>>X;
    string Y;
    cin>>Y;

    int m = X.length();
    int n = Y.length();

    vector<vector<int>> L(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    cout << "Length of LCS: " << L[m][n] << endl;

    return 0;
}