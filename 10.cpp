#include <iostream>

using namespace std;

int main() {
    const int n = 5;
    int a[n][n];
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = rand() % 100 + 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
    int iM = 0, jM = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][i] > a[iM][jM]) {
            iM = jM = i;
        }
        if (a[i][n - i - 1] > a[iM][jM]) {
            iM = i;
            jM = n - i - 1;
        }
    }
    double t = a[n / 2][n / 2];
    a[n / 2][n / 2] = a[iM][jM];
    a[iM][jM] = t;
    printf("\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;

}
