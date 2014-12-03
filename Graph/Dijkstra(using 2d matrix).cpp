// prints shortest dist from all vertices to source
#include<bits/stdc++.h>
int minimumDist(int dist[], int vertexIncluded[],int V)
{
     int min = INT_MAX, min_index;
     int v =0;
     for (v = 0; v < V; v++)
       if (vertexIncluded[v] == 0 && dist[v] <= min)
       {
               min = dist[v];
               min_index = v;
       }
     return min_index;
}
void printSolution(int dist[], int V)
{
 int i=0;
 for ( i = 0; i < V-1; i++)
    printf("%d ",dist[i]);
    printf("%d",dist[V-1]);
}

void SSSP(int **gr, int s,int V)
{
  int dist[V],i,j,k;
   for (i = 0; i < V; i++)
   {
    for (j = 0; j < V; j++)
   {
      if(gr[i][j]>100 || gr[i][j]<1)
      gr[i][j]=9999;
      }
   }
   for (i = 0; i < V; i++)
   {
    for (j = 0; j < V; j++)
   {
      for (k = 0; k < V; k++)
  {
         if (gr[j][k] > gr[j][i] + gr[i][k])
    {
           gr[j][k] = gr[j][i] + gr[i][k];
           }
         }
      }
   }
   gr[s][s]=0;
   for (i = 0; i < V; i++)
   {
    dist[i]=gr[i][s];
   }
   printSolution(dist,V);

}

int main()
{
    int V,E;
    int **graph;
    // The vertices are numbered from 0 to V-1
    scanf("%d %d",&V,&E);
    graph = (int **)malloc(sizeof(int *)*V);
    int i=0;
    for(i=0;i<V;i++)
    graph[i] = (int *)malloc(sizeof(int)*V);

    for(i=0;i<E;i++)
    {
        int s,d,w;
        scanf("%d%d%d",&s,&d,&w);
        graph[s][d] = w;
        graph[d][s] = w;
    }

    SSSP(graph, 0,V);

  return 0;
}
