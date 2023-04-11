#include<stdio.h>


void mcm(int arr[], int n, int M[n][n], int K[n][n]) {
    for (int i = 1; i < n; i++)
        M[i][i] = 0;


    for (int d = 2; d < n; d++) {
        for (int i = 1; i < n - d + 1; i++) {
            int j = i + d - 1;
            M[i][j] = 99999; 

            for (int k = i; k < j; k++) {
                int cost = M[i][k] + M[k+1][j] + arr[i-1] * arr[k] * arr[j];
                if (cost < M[i][j]) {
                    M[i][j] = cost;
                    K[i][j] = k;
                }
            }
        }
    }

    printf("The minimum number of scaler multiplications required: %d", M[1][n-1]);
}
int main(){
    int n=5;
    int arr[5] = {40,20,30,10,30};
    int M[n][n];
    int K[n][n];
    mcm(arr, n,M,K);


    return 0;
}