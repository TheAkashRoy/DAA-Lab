#include <stdio.h>
void towerOfHanoi(int n, int A, int B,int C, int D);
void TOH3(int n, int A, int B, int C)
{
    if (n == 0)
        return;
    TOH3(n - 1, A, C, B);
    printf("\nmove the disk of %d to %d ", A, C);
    TOH3(n - 1, B, A, C);
}

void TOH4(int n, int A, int B, int C, int D)
{
    if (n == 0)
        return;
    if (n == 1)
    {
        printf("\nmove the disk of %d to %d ", A, D);
        return;
    }

    int k = n / 2;
    TOH4(k, A, C, D, B);
    TOH3(n - k - 1, A, D, C);
    // printf("\nmove the disk of %d to %d ",A,D);
    printf("\nmove the disk of %d to %d ", A, D);
    TOH3(n - k - 1, C, A, D);
    TOH4(k, B, A, C, D);
}

int main()
{
    int n;
    printf("Enter the no. of discs: ");
    scanf("%d", &n);
    // TOH3(4,1,2,3);
    // TOH4(n, 1, 2, 3, 4);

    towerOfHanoi(n, 1, 2, 3, 4);
    return 0;
}

void towerOfHanoi(int n, int A, int B,int C, int D)
{
    if (n == 0)
        return;
    if (n == 1)
    {
        printf("\n Move disk %d from rod %d to rod %d",
               n, A, B);
        return;
    }

    towerOfHanoi(n - 2, A, C, D,B);
    printf("\n Move disk %d from rod %d to rod %d ",n - 1, A, D);
    printf("\n Move disk %d from rod %d to rod %d ",n, A, B);
    printf("\n Move disk %d from rod %d to rod %d ", n - 1, D, B);
    towerOfHanoi(n - 2, C, B, A,D);
}
