#include<stdio.h>
#include<math.h>

int eqn(int x){
    int eqn1 = pow(x,3) -10*pow(x,2) -15*x -20;
    int eqn2 = pow(x,2)-10;
    int eqn3 = x-10;
    return eqn3;
}

float gaussianFun(float x){
    float a=25;
    float b=25;
    float c=1;
    
    return a*exp(-1*(pow(x-b,2)/(2*pow(c,2))));
}

int findzero(){
    if(eqn(0)==0) return 0;
    int i=1;
    while(eqn(i)<=0)
        i=i*2;
    int s = i/2, e = i;
    while (s<e){
        int mid = s + (e-s)/2;
        if(eqn(mid)==0)
            return mid; 
        if(eqn(mid)<0){
            s=mid+1;
        }else{
            e=mid;
        }
    }
    return -1;
}

int peakZero(){
    if(gaussianFun(0)>gaussianFun(1))
        return 0;
    float i=1;
    while (gaussianFun(i)>gaussianFun(i-1))
        i=i*2;
    int s = i/2, e = i;
    while (s<e){
        int mid = s + (e-s)/2;
        if(gaussianFun(mid)>gaussianFun(mid-1) && gaussianFun(mid)>gaussianFun(mid+1))
            return mid; 
        if(gaussianFun(mid)>gaussianFun(mid-1)){
            s=mid+1;
        }else{
            e=mid;
        }
    }
    return -1;
    
}

int binarySearch(int arr[], int n, int key){
    int s=0, e=n-1;
    while (s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid]==key)
            return mid;
        if(arr[mid]>arr[s]){
            if(key>=arr[s] && key<arr[mid]){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }else{
            if(key>arr[mid] && key<=arr[e]){
                s = mid+1;
            }else{
                e = mid-1;
            }           
        }
    }
    return -1;
}

int main(){
    int arr[] = {5,10,15,1,2,3};
    printf("%d",findzero());
    // printf("\n%d",peakZero());
    

    return 0;
}