#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
struct Edge{
	 int source, destination, weight;};
struct Graph{
    int V, E;
// V là so dinh E la so canh
    struct Edge* edge;
};
 
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph));
//phân bổ không gian cho đồ thị
    graph->V = V; 
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
//Tạo cấu trúc cạnh bên trong cấu trúc đồ thị, số cấu trúc kiểu cạnh bằng số canh
    return graph;
}
 
void FinalSolution(int dist[], int n)
{
    printf("\nVecto\tkhoang cach tu dinh nguon\n");
    int i;
 
    for (i = 0; i < n; ++i){
	    printf("%d \t\t %d\n", i, dist[i]);}
}
 
void BellmanFord(struct Graph* graph, int source)
{
    int V = graph->V;
 
    int E = graph->E;
 
    int StoreDistance[V];
 
    int i,j;
 
    for (i = 0; i < V; i++)
        StoreDistance[i] = INT_MAX;
 
    StoreDistance[source] = 0;
 
    for (i = 1; i <= V-1; i++)
    {
        for (j = 0; j < E; j++)
        {
            int u = graph->edge[j].source;
 
            int v = graph->edge[j].destination;
 
            int weight = graph->edge[j].weight;
 
            if (StoreDistance[u] + weight < StoreDistance[v])
                StoreDistance[v] = StoreDistance[u] + weight;
        }
    }
 
    for (i = 0; i < E; i++)
    {
        int u = graph->edge[i].source;
 
        int v = graph->edge[i].destination;
 
        int weight = graph->edge[i].weight;
 
        if (StoreDistance[u] + weight < StoreDistance[v])
            printf("Do thi chua chu trinh canh am\n");
    }
 
    FinalSolution(StoreDistance, V);
 
    return;
}
 
int main(){
    int V,E,S;  
 
printf("Nhap so dinh\n");
    scanf("%d",&V);
 
printf("nhap so canh\n");
    scanf("%d",&E);
 
printf("Nhap so dinh bat dau\n");
scanf("%d",&S);
 
    struct Graph* graph = createGraph(V, E); 
 
    int i;
    for(i=0;i<E;i++){
        printf("\nNhap canh %d dinh dau, ket thuc, trong so\n",i+1);
        scanf("%d",&graph->edge[i].source);
        scanf("%d",&graph->edge[i].destination);
        scanf("%d",&graph->edge[i].weight);
    }
 
    BellmanFord(graph, S);
    return 0;
}
