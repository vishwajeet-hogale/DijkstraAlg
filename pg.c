#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int** createGraph(int n){
    int **graph = (int**)malloc(n*sizeof(int*));
    int i=0;
    for(i=0;i<n;i++){
        graph[i] = (int*)malloc(n*sizeof(int));
    }
    printf("Enter the weights in the graph ");
    int j;int x;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Enter the weight in (%d,%d)",i,j);
            scanf("%d",&graph[i][j]);
        }
    }
    return graph;
}


int calcMindis(int dist[],int sptSet[],const int n){

   // Initialize min value
   int min = 10000, min_index;
 
   for (int v = 0; v < n; v++)
     if (sptSet[v] == 0 && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;

}
void dijkstra(int **g, int src,const int n){
    int dis[n];
    
 
    int sptSet[n]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
 
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < n; i++){
        sptSet[i] = 0;dis[i] = 10000;}
        dis[0] = 0;
    for(int c = 0;c<n-1;c++){
        int u = calcMindis(dis,sptSet,n);
        sptSet[u] = 1;
        for (int v = 0; v < n; v++)
 
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && g[u][v] && dis[u] != 10000
                                       && dis[u]+g[u][v] < dis[v])
            dis[v] = dis[u] + g[u][v];
     }
        int i=0;
        prinf("\nDistances are :");
        for(i=0;i<n;i++){
            printf("%d,",dis[i]);
        }
    }
    

void main(){
    int i,j,n;
    printf("Enter the number:");
    scanf("%d",&n);
    int **g = createGraph(n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
    printf("---------------------");
    printf("Graph created!");
    // int g[5][5] = {
    //     {0,10,1,0,0},
    //     {0,0,0,0,5},
    //     {0,0,0,2,0},
    //     {0,2,4,0,4},
    //     {0,0,0,0,0}
    // };
    dijkstra(g,0,5);
}