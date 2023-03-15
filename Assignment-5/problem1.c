#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int* generate_array(int n, int j, int k) {
    int* A = (int*)malloc(n * sizeof(int));
    srand(time(NULL)); 
    for (int i = 0; i < n; i++) {
        A[i] = (rand() % (k-j+1))+j; 
    }
    return A;
}

void countingSort(int* a, int n, int j, int k){
    int count[k-j+1];
    for (int i = 0; i < (k-j+1); i++){
        count[i]=0;
    }

    for (int i = 0; i < n; i++){
        count[a[i]-j]++;
    }
    int index=0;
    for(int i=0;i<k-j+1;i++){
        for (int t = 0; t < count[i]; t++)
        {
            a[index]=i+j;
            index++;
        }
        
    }
}


int main(){
    int* A = generate_array(5, 10, 15);
    for (int i = 0; i < 5; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    countingSort(A,5,10,15);
    for (int i = 0; i < 5; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}