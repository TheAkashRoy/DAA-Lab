#include<iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

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

void BucketSort(int* arr, int n, int k){
    int max_val = arr[0];
    for(int i= 1;i<n;i++)
        max_val = max(max_val,arr[i]);
    max_val++;
    vector<int> bucket[k];
    for (int i = 0; i < n; i++){
        int bi = (k*arr[i])/max_val;
        bucket[bi].push_back(arr[i]);
    }
    
    for(int i = 0;i<k;i++){
        sort(bucket[i].begin(),bucket[i].end());
    }

    int index =0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < bucket[i].size(); j++)
        {
            arr[index++] = bucket[i][j];
        }
        
    }
    

}

int main(){
    int* A = generate_array(15, 10, 15);
    for (int i = 0; i < 15; i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    countingSort(A,5,10,15);
    //BucketSort(A,15,3);
    for (int i = 0; i < 15; i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;

    return 0;
}