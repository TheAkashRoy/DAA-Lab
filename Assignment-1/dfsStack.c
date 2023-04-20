#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAP 50

typedef struct stack
{
    int arr [CAP];
    int top;
}stack;


stack* initilize_stack ()
{
    stack *ptr = (stack*) malloc (sizeof (stack));
    if (!ptr)
    {
        perror ("stack create fail\n");
        return NULL;
    }
    for (int i = 0; i < CAP; i++)
        ptr->arr[i] = 0;    
    ptr->top = -1;
    return ptr;
}

void push (stack* ptr, int val)
{
    if (ptr->top == CAP-1)
    {
        printf ("Stack overflow\n");
        // return false;
    }
    ptr->top++;
    ptr->arr [ptr->top] = val;
    // return true;
}

int pop (stack* ptr)
{
    if (ptr->top == -1)
    {
        printf ("Stack underflow\n");
        // return false;
    }
    int ret = ptr->arr [ptr->top];
    ptr->top--;
    return ret;
}

bool peek (stack* ptr, int* ret)
{
    if (ptr->top == -1)
        return false;
    *ret = ptr->arr [ptr->top];
    return true;
}

void display (stack* ptr)
{
    if (ptr->top == -1)
        printf ("Stack empty\n");
    else
    {
        printf ("||    %d\t|| <-- [top]\n", ptr->arr [ptr->top]);
        for (int i = ptr->top - 1; i >= 0 ; i--)
            printf ("||    %d\t||\n", ptr->arr [i]);
    }
}

int isEmpty(stack* ptr){
    if(ptr->top==-1){
        return 1;
    }else{
        return 0;
    }
}

void graph(int n, int e, int g[n][n]){
    for (int i = 1; i <n; i++){
        for (int j = 1; j <n; j++){
           g[i][j]=0; 
        }  
    }
    
    printf("enter the connected edges:\n");
    for (int i = 0; i < e; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        g[a][b]=1;
        g[b][a]=1;
    }
}

void dfs(int n , int g[n][n], int start){
    stack* sptr = initilize_stack ();
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i]=0;
    visited[start]=1;
    push(sptr,start);
    while(!isEmpty(sptr)){
        int t = pop(sptr);
        // visited[t]=1;
        printf("%d ",t);
        for (int i = 1; i < n; i++){
            if(g[t][i]==1 && visited[i]==0){
                push(sptr,i);
                visited[t]=1;
            }
        }
        

    }
}


int main(){
    int n,e;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    int g[n+1][n+1];
    printf("Enter the number of edges: ");
    scanf("%d",&e);
    graph(n+1,e,g);

    // for (int i = 1; i <= n; i++){
    //     for (int  j = 1; j <= n; j++){
    //         printf("%d ", g[i][j]);
    //     }
    //     printf("\n");
    // }
    int start;
    printf("\nenter the starting node: ");
    scanf("%d",&start);
    dfs(n+1,g,start);

    return 0;
}