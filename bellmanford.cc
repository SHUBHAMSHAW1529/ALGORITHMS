#include<bits/stdc++.h>
using namespace std;
struct Edge
{
 int src;//source//
 int dest;//destination//
 int weight;//weight//
};
struct Graph
{
 int V;
 int E;
 struct Edge * edge;//array of edges//

};
void print_array(int *d,int n)
{
 for(int i=0;i<n;i++)
  printf("%d ",d[i]);
  printf("\n");
}
struct Graph * create_graph(int v,int e)
{
 struct Graph *graph=(struct Graph *)malloc(sizeof(struct Graph));
 graph->V=v;
 graph->E=e;
 graph->edge=(struct Edge *)malloc(e*sizeof(struct Edge));
 return graph;
}
void bellman_ford(struct Graph * graph,int src)
{
 int v=graph->V;
 int e=graph->E;
 int dist[v];
 bool f=true;
 dist[src]=0;
 for(int i=0;i<v;i++)
 {
  if(i!=src)
  dist[i]=INT_MAX;
 }
 int u,d,w;
 for(int i=0;i<v-1;i++)
 {
  for(int j=0;j<e;j++)
  {
   u=graph->edge[j].src;
   d=graph->edge[j].dest;
   w=graph->edge[j].weight;
   if(dist[d]>dist[u]+w)
    dist[d]=dist[u]+w;
  }
 }
 for(int j=0;j<e;j++)
 {
   u=graph->edge[j].src;
   v=graph->edge[j].dest;
   w=graph->edge[j].weight;
  if(dist[v]>dist[u]+w)
  {
   printf("graph contains negative cycle\n");
   f=false;
   break;
  }

 }
 if(f)
 {
  printf("shortest distance of vertices in their order are:\n");
  print_array(dist,v);
 }

}
int main()
{
 int v,e,s,d,w,src;
 cout<<"enter number of vertices:\n";
 cin>>v;
 cout<<"enter number of edges:\n";
 cin>>e;
 struct Graph * graph=create_graph(v,e);
 cout<<"enter edges:\n";
 for(int i=0;i<e;i++)
 {
  cin>>s>>d>>w;
  graph->edge[i].src=s;
  graph->edge[i].dest=d;
  graph->edge[i].weight=w;
 }
 cout<<"enter source vertex:\n";
 cin>>src;
 bellman_ford(graph,src);
 return 0;
}
