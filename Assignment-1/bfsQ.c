#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAP 50

typedef struct queue
{
    int arr [CAP];
    int front, rear;
}queue;


queue* initilize_queue ()
{
    queue *ptr = (queue*) malloc (sizeof (queue));
    if (!ptr)
    {
        perror ("QUEUE create fail\n");
        return NULL;
    }
    for (int i = 0; i < CAP; i++)
        ptr->arr[i] = 0;    
    ptr->rear = ptr->front = -1;
    return ptr;
}

void enqueue (queue* ptr, int val)
{
    if (ptr->rear == CAP-1)
    {
        printf ("QUEUE overflow\n");
    }
    if (ptr->rear == -1)
        ptr->front++;
    ptr->rear++;
    ptr->arr [ptr->rear] = val;
}

int dequeue (queue* ptr)
{
    if (ptr->front > ptr->rear)
    {
        printf ("QUEUE underflow\n");
        return 0;
    }
    int ret = ptr->arr [ptr->front];
    ptr->front++;
    return ret;
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

void display (queue* ptr)
{
    if (ptr->front == -1 || ptr->front > ptr->rear)
        printf ("QUEUE empty\n");
    else
    {
        printf ("\nQUEUE:: [FRONT]==");
        for (int i = ptr->front; i <= ptr->rear; i++)
            printf ("%d==", ptr->arr [i]);
        printf ("[REAR]\n");
    }
    printf("\nStructure contents:\nSTORAGE:: -");
    for (int i = 0; i < CAP ; i++)
        printf (" [%d]->%d -", i, ptr->arr [i]);
    printf("\nFRONT = [%d], REAR = [%d]\n", ptr->front, ptr->rear);
}


int isEmpty(queue* qptr){
    if(qptr->front>qptr->rear){
        return 1;
    }else{
        return 0;
    }
}


void bfs(int n, int g[n][n], int start){
    queue* qptr = initilize_queue ();
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i]=0;
    enqueue(qptr,start);
    visited[start] = 1;
    while (!isEmpty(qptr)){
        int t = dequeue(qptr);
        printf("%d ",t);
        for (int i = 1; i < n; i++){
            if(g[t][i]==1 && visited[i]==0){
                enqueue(qptr,i);
                visited[i]=1;
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
    bfs(n+1,g,start);

    return 0;
}